class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

            // my vars 
            unordered_map<int,int> numberCounts; //maping number -> freq.
            vector<int> answerVector;
            
            //populate the map - doesnt matter if seen before or not
            //count starts at 0 .. the ++ makes it one..BOOM and the freq is logged 
            for(auto currNum: nums) 
                numberCounts[currNum]++;
            

            //extract top k elements from map 
            for(int i = 0; i < k; i++) {
                //find max each run through 

                int max = 0;
                int maxKey = 0;

                for(auto pair : numberCounts) {
                    int count = pair.second;
                    int keyNum = pair.first;

                    if(count > max ) {
                        max = count;
                        maxKey = keyNum;
                    }
                }
                //add max to vector 
                answerVector.push_back(maxKey);
                //delete top entry 
                numberCounts.erase(maxKey); // by using key 
            }

        return answerVector;
    }
};
