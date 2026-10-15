class Solution {
public:
    bool isPalindrome(int x) {
        //two pointer pattern

        //turn number to string to traverse 
        string num = to_string(x);

        //my two pointers
        int pLeft = 0;
        int pRight = num.length() - 1;

        while(pLeft < pRight) {
            if(num[pLeft]==num[pRight]) {
                pLeft++;
                pRight--;
            } else {
                return false;
            } 
        }

        return true;

    }
};
