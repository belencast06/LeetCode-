class Solution {
public:
    int reverseDegree(string s) {
        //string stringAlpha= "zyxwvutsrqponmlkjihgfedcba";
        int sum = 0;

        for(int i=0;i<s.length();i++) { //index starting at 1 for letter 
            //int charIndex = (26 - (s[i]-'a'));
            sum += (26 - (s[i]-'a'))*(i+1);
        }

        return sum; 
    }
};
