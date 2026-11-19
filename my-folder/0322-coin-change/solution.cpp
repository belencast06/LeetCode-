//#include <algorithm>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        //base case - amount || coins is zero && coin is less than ammount
        if(coins.size() == 0)
            return -1; 

        if(amount == 0) 
            return 0;
        
        //sort coins in order first
        sort(coins.begin(),coins.end());

        //there will be 1 - 12 diff types of coins --> values range can be held in int 
        //coins may be used as many times as possible.
        vector<int> dpMinCoins(amount+1,amount+1);
        dpMinCoins[0] = 0;

        for(int i=1; i <= amount;i++) {

            //try each coin 
            for(const int& coin: coins) {

                //leave if coin in larger than curr sub amount 
                if(coin > i) 
                    break;
                else 
                    //take this coin or take prev coin 
                    dpMinCoins[i] = min(dpMinCoins[i], 1 + dpMinCoins[i-coin]);
            }

        }

        if(dpMinCoins[amount] > amount)
            return -1;

        return dpMinCoins[amount];

        
    }
};
