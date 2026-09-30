class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //unordered map -- values --> index
        unordered_map<int,int> seenNums;

        for(int i=0;i<nums.size();i++) {

            //finding diff so we can search for pair that makes target 
            int diff = target - nums[i];

            if(seenNums.count(diff)){
                return {seenNums[diff],i};
            }

            seenNums[nums[i]] = i;
        }
       return {}; //no solution 
    }
};


//  vector<int> answers;

//         for(int i=0;i<nums.size()-1;i++) {
//             for(int j=1;j<nums.size();j++) {
//                 if(nums[i]+ nums[j] == target) {
//                     answers.push_back(i);
//                     answers.push_back(j);
//                 }
//             }
//         }
//         return answers;
