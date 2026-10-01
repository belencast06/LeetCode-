class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //base case - empty or single char string
        if(s.length() == 0 || s.length() == 1) 
            return s.length();

        //create two pointers - Left and Right 
        //both start @ zero (window size of 1)
        int pLeft = 0;
        int pRight = 0;

        //holds visted chars last known index 
        // char - > last know index 
        unordered_map<char,int> visited;

        //max window size 
        int maxWindow = 0;
        

        while( pRight < s.length()) { //while in bound of string 
            char c = s[pRight];
            if(visited.count(c)&&visited[c] >= pLeft) {
 
                //and update left pointer to last seen..
                pLeft = visited[c] + 1; //hop to next over (new window)
               
            }
            visited[c] = pRight;

            //with second part holding current Window
            maxWindow = max(maxWindow, pRight - pLeft + 1);  
            pRight++; //if not found then keep going 
        }
        return maxWindow;
    }
};
