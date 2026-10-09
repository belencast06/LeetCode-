class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //base case - nums are size 1

        //vars
        unordered_map<int,int> valIndex;
        stack<int> decreasing;

        //lets go through nums2
        for(int i = 0; i < nums2.size(); i++) {
            int currEle = nums2[i]; //currEle = 1 
            // ^ a potential next greater

            //start stack loop from right index ? 
            while(!decreasing.empty() && currEle > decreasing.top()) {
                //get value to be popped - currently @ top 
                int hasNextGreater = decreasing.top();
                decreasing.pop(); //now pop it 
                //map the values NGInt 
                valIndex[hasNextGreater] = currEle;
            }
            decreasing.push(currEle);
        }

        //go through nums1 and place next greaters 
        for(int i = 0; i < nums1.size(); i++) {
            //if found in map (has next greater) else put -1 
            if(valIndex.count(nums1[i]))
                nums1[i] = valIndex[nums1[i]];
            else 
                nums1[i] = -1;
        }

        return nums1;
    }
};
