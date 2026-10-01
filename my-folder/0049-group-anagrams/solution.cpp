class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //mapping | key -> value
        unordered_map<string, vector<string>> letters;
        vector<vector<string>> output;

        //sort each word chars into abc order - make that the key
        // and add it to the bucket if found 

        //populate the map !
        for(int i=0; i< strs.size(); i++) {

            string key = strs[i];
            sort(key.begin(),key.end());

            letters[key].push_back(strs[i]);
        }

        for(auto i: letters) {
            output.push_back(i.second);
        }

        return output;
    }
};
