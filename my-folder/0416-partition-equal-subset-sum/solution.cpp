class Solution {
public:
    bool canPartition(vector<int>& nums) {

        //looking for buckets with difference of zero, close the gap 
        //single set to hold unique sums
        unordered_set<int> dpSums;
        int sumTotal = 0;

        for(auto const& num: nums) 
            sumTotal +=num;

        //base case - odd total
        if(sumTotal%2!=0)    
            return false; //not possible to partition 

        //start dpSet 
        dpSums.insert(0); //starting sum of zero (always possible)
       
       //var for target 
       int target = sumTotal/2;

        for(const int& num: nums) {
            unordered_set<int> copyDp;

            for(const int& sum: dpSums)   { 
                if((sum + num) == target) return true;

                copyDp.insert(sum); //put curr num

                if((sum + num) < target) { //ignore sum if too large 
                copyDp.insert(sum + num);
                }
            }

            dpSums = move(copyDp);
        }

        return dpSums.contains(target);
        
    }
};
