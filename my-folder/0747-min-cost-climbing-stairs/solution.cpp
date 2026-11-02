class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //edge cases 
        if(cost.size()==1) 
            return cost[0];

        if(cost.size()==2)  
            return min(cost[0],cost[1]);

        vector<int> dp(cost.size()+1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        //loop through
        for(int i = 2;i<cost.size();i++) {
            dp[i] = min(cost[i]+dp[i-2], cost[i] + dp[i-1]);
        }

        return min(dp[cost.size()-2],dp[cost.size()-1]);
        
    }
};
