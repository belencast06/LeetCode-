class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0) //if even gcd will be 2
        return n;
        else //if odd gcd will be 1 
        return 2*n;
    }
};
