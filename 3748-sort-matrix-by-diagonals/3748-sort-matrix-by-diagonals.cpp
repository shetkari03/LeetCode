class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            int m=n-i;
            for(int k=0;k<m;k++){
                int r=i+1,c=1;
                for(int l=0;l<m-1;l++){
                    if(grid[r-1][c-1]<grid[r][c]){
                        swap(grid[r][c],grid[r-1][c-1]);
                    }
                    r++;
                    c++;
                }
            }
        }
        for(int i=1;i<n;i++){
            int m=n-i;
            for(int k=0;k<m;k++){
                int r=1,c=i+1;
                for(int l=0;l<m-1;l++){
                    if(grid[r-1][c-1]>grid[r][c]){
                        swap(grid[r][c],grid[r-1][c-1]);
                    }
                    r++;
                    c++;
                }
            }
        }
        return grid;
    }
};