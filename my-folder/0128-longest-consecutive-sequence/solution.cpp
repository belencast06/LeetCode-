class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
    int longestSeq=0;
    unordered_set<int> presentNums;

    //populate the map
    for(auto num : nums)    
        presentNums.insert(num);

    //traverse list to look for diff of 1
    for(auto num : presentNums) {

        int curr = 0, length = 0;

        if(!presentNums.contains(num-1)) {
            curr = num;
            length = 1;

            while(presentNums.contains(curr+1)) {
                curr++;
                length++;
            }
        }


        longestSeq = max(longestSeq, length);
    }

    return longestSeq;
    }
};
