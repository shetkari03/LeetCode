class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        int row[3]={-1,0,1};
        int col[3]={-1,-1,-1};
        for(int i=0;i<n;i++)dp[i][0]=1;
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                for(int k=0;k<3;k++){
                    int r=i+row[k],c=j+col[k];
                    if(r>=0 && r<n && c>=0 && c<m && grid[i][j]>grid[r][c] && dp[r][c]>0){
                        int d=dp[r][c]+1;
                        dp[i][j]=dp[i][j]>d?dp[i][j]:d;
                    }
                }
                ans=ans>dp[i][j]?ans:dp[i][j];
            }
        }
        if(ans==0)return 0;
        return ans-1;
    }
};