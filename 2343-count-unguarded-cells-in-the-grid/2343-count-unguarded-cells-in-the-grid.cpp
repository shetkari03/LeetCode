class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto it:walls)grid[it[0]][it[1]]=2;
        for(auto it:guards){
            grid[it[0]][it[1]]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1)continue;
                for(int row=i-1;row>=0;row--){
                    if(grid[row][j]==1 || grid[row][j]==2)break;
                    grid[row][j]=3;
                }
                for(int row=i+1;row<m;row++){
                    if(grid[row][j]==1 || grid[row][j]==2)break;
                    grid[row][j]=3;
                }
                for(int col=j-1;col>=0;col--){
                    if(grid[i][col]==1 || grid[i][col]==2)break;
                    grid[i][col]=3;
                }
                for(int col=j+1;col<n;col++){
                    if(grid[i][col]==1 || grid[i][col]==2)break;
                    grid[i][col]=3;
                }
            }
        }
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)ct++;
            }
        }
        return ct;
    }
};