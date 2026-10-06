class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

            // my vars 
            unordered_map<int,int> numberCounts; //maping number -> freq.
            vector<int> answerVector;
            
            //populate the map - doesnt matter if seen before or not
            //count starts at 0 .. the ++ makes it one..BOOM and the freq is logged 
            for(auto currNum: nums) 
            //no const auto& bc only looking at ints 
                numberCounts[currNum]++;
            
            //make PriQ for a min-heap 
            //map {freq, value} - compares.firsts for ordering
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

            //fill the minHeap 
            for(const auto& group : numberCounts) {
                minHeap.push({group.second, group.first});

                //remove smallest if we go over k size
                if(minHeap.size() > k)
                    minHeap.pop(); //remove smallest freq 
            }

            //extract items from minHeap -> answerVector 
            while(!minHeap.empty()) {
                answerVector.push_back(minHeap.top().second); //get top.second to get value not freq 
                minHeap.pop(); //remove old top to get next num
            }

        return answerVector;
    }
};

//saftey measure 
//const for read only and & to pass var directly  
// brute n^2 soultion 
//extract top k elements from map 
            // for(int i = 0; i < k; i++) {
            //     //find max each run through 

            //     int max = 0;
            //     int maxKey = 0;

            //     for(auto pair : numberCounts) {
            //         int count = pair.second;
            //         int keyNum = pair.first;

            //         if(count > max ) {
            //             max = count;
            //             maxKey = keyNum;
            //         }
            //     }
            //     //add max to vector 
            //     answerVector.push_back(maxKey);
            //     //delete top entry 
            //     numberCounts.erase(maxKey); // by using key 
            // }
