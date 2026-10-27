class Solution {
public:
    int hasCycle(vector<vector<int>>& adj, int courses) {
        //make degreeArr -- all set to zero
        vector<int> inDegree(courses, 0);
        vector<int> tOrder; 
        queue<int> q; 

        //calc degrees 
        for(int i = 0; i < courses; i++) {
            for(int prereq: adj[i]) {
                inDegree[prereq]++;
            }
        }

        //put degrees in queue 
        for(int i = 0; i < courses; i++) {
            if(inDegree[i]==0)  
                q.push(i);
        } 

        //go through verts 
        while(!q.empty()) {
            int u = q.front(); 
            q.pop(); //pop front now that stored 
            tOrder.push_back(u);

            //reduce degree for neighbors 
            for(int v : adj[u]) {
                inDegree[v]--; //decrease by one 

                if(inDegree[v]==0) //if neighbor has no dependencies then push !
                    q.push(v);
            }
        }

       return tOrder.size();
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //make map - adj - size of numCourses
        vector<vector<int>> adj(numCourses);
        int indexA = 0, indexB = 1;

        //single - directed from bi -> ai (unweighted)
        //add edges 
        for(int i = 0; i < prerequisites.size(); i++) {
            //need like 0 --> 1 edge (directed one way)
            //needs to {0 -> 1} input {1, 0}
            //[i][b] - prereq --> [i][a] - course
            adj[prerequisites[i][indexB]].push_back(prerequisites[i][indexA]); 
        }

        //now make valid path - could use bread crumbs 
        // BFS to look for cycle 
        //function of kahns algorithm (asj, numCourses, startNode(?))
        int cycleCheck = hasCycle(adj,numCourses);

    
        return (cycleCheck == numCourses);
    
    }
};
