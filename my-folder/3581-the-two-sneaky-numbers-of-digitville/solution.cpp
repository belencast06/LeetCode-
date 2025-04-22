class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
         unordered_set<int> notSneaky; 
         vector<int> sneaky;

        int vecSize= nums.size();

        for(int i=0;i<vecSize;i++) {
            if(notSneaky.find(nums[i])!=notSneaky.end())
            sneaky.push_back(nums[i]);
            else{
            notSneaky.insert(nums[i]);
            }

        }

        return sneaky;
    }
};
