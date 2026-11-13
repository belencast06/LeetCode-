class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //only check for words that are actually in the string 

        unordered_set<string> words;
        int startIndex =0;
        
        //make dp vector of return type
        vector<bool> dp(s.length()+1,false); //so we only check and alter TRUES
        //base case - true 
        dp[0] = true;


        //populate the set 
        for(const auto& word: wordDict) 
            words.insert(word);

        for(int i =1;i<=s.length();i++) {
            for(startIndex= 0;startIndex < i;startIndex++){
                //check if string[0...startIndex] is breakable (will be true)
                // and if string[startindex to i] is a word 
                if(dp[startIndex] && words.count(s.substr(startIndex, i -startIndex))) {
                    cout<<dp[startIndex]<<endl;
                    cout<<startIndex<<endl;
                    cout<<i<<endl;
                    cout<<s.substr(startIndex,i-startIndex)<<endl;
                    //^ie dont check a word if its too long 
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
        
    }
};
