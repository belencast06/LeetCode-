class Solution {
public:
    bool isPalindrome(int x) {

        //non two pointer method 

        //base case - negative numbers + numbers ending in zero (if not 0)
        if(x < 0 || (x%10==0 && x !=0))
            return false;


        //variables
        int rNum = 0; //will hold my reverse of x result

        //only go through half of the number and reversed to avoid overflow 
        while(rNum < x) {

            //extracted digit * 10 to build the correct tens place before adding 
            rNum = (rNum*10) + (x%10);
            //divide x to continue working right to left 
            x/=10;
        }
        
        // cout<<"This is rNum:"<<rNum<<endl;
        // cout<<"This is x: "<<x<<endl;
        
        //divide odd numbers by 10 at end 
        // ie. 2 == 12/10 (or just 2) for 121
        return ( x == rNum || x == rNum/10);
        
    }
};
