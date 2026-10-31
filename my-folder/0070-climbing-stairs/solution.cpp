class Solution {
public:
    int climbStairs(int n) {
        
        //dynamic programming approach - bottom up 

        int prev1=1,prev2=1;

        for(int i = 2;i<=n;i++) {
            int curr = prev1 + prev2;

            //now swap to move up stairs
            prev2 = prev1; 
            prev1 = curr;
        }

        return prev1;
    }
};
