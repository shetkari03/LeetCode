class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    int ct=0;
                    vis[i][j]=1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        ct+=grid[r][c];
                        for(int k=0;k<4;k++){
                            int nr=r+row[k],nc=col[k]+c;
                            if(nr>=0 && nr<n && nc>=0 && nc<m && 
                                   !vis[nr][nc] && grid[nr][nc]>0){
                                    q.push({nr,nc});
                                    vis[nr][nc]=1;
                                   }
                            
                        }
                    }
                    ans=max(ans,ct);
                }
            }
        }
        return ans;

    }
};