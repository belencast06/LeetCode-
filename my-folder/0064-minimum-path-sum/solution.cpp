class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        //traverse matrix in some way to compare paths at end 
        //get rows and cols 
        int rows = grid.size();
        int cols = grid[0].size();

        //number of (n+m) paths - end box is m-1,n-1 
        vector<vector<int>> gridDp(rows, vector<int>(cols));
        //give start value 
        gridDp[0][0] = grid[0][0]; //start value 


        for(int r = 0; r < rows; r++) {
            for(int c = 0; c<cols;c++) {
                //base case of start box
                if(r==0&&c==0) continue;
                
                if(r ==0 && c!=0) { //coming from left (move right)
                    gridDp[r][c] = gridDp[r][c-1] + grid[r][c];
                }else if(c==0 && r!=0) { //coming from above (move down)
                    gridDp[r][c] = gridDp[r-1][c] + grid[r][c];
                }else { //for any other square take a min of down or right
                    gridDp[r][c] = min(gridDp[r][c-1], gridDp[r-1][c]) + grid[r][c];
                }

            }
        }

        return gridDp[rows-1][cols-1]; // for 0-indexing 
        
    }
};
