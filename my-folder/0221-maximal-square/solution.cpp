class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //need a sqaure so length == width 
        //max possible sqaure is m=n (where smallest sets the base)
        int rows = matrix.size();
        int cols = matrix[0].size();

        int validSide = 0;
        vector<vector<int>> gridDp(rows,vector<int>(cols,0)); //default all 0

        //traverse and visit each sqaure - look for valid groups of 2 
        for(int r = 0; r<rows;r++) {
            for(int c=0; c<cols;c++) {

                //go left, up, diagonal up - only if we have a 1 square 
                if(matrix[r][c]== '1') {

                    //if row or col are 0 then max size is 1 
                    if(r == 0 || c == 0) 
                        gridDp[r][c] = 1;
                    else //if 0 is min then stays at 1 value 
                        gridDp[r][c] = 1 + min({gridDp[r-1][c],gridDp[r][c-1],gridDp[r-1][c-1]});
               
                }
                //cout<<gridDp[r][c]<<endl;
                //cout<<validSide<<endl;
                validSide = max(validSide,gridDp[r][c]); //keep max 
            }
        }

        return validSide * validSide;

    }
};
