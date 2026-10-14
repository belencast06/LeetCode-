class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        //stores indexes in desending order
        stack<int> indexes;
        //vector holding answers 
        vector<int> warmer(temperatures.size(),0);

        for(int i =0;i<temperatures.size();i++) {
            
            //maintain stack
            while(!indexes.empty() && temperatures[i] > temperatures[indexes.top()]) {
                int prevIndex = indexes.top(); //we now have greater
                //pop top 
                indexes.pop();

                warmer[prevIndex] = i - prevIndex;
            }
            indexes.push(i);
        }
        
        //if untouched then had no warmer 
        return warmer;

    }
};
