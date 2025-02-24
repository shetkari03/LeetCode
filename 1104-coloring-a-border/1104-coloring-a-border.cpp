class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        queue<pair<int,int>>q;
        vector<vector<int>>ans=grid;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int arr[4]={0,-1,0,1};
        int arc[4]={-1,0,1,0};
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int ct=0;
            for(int i=0;i<4;i++){
                int nr=r+arr[i],nc=c+arc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                    if(grid[nr][nc]!=grid[row][col])continue;
                    ct++;
                    if(!vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            if(ct<4){
                ans[r][c]=color;
            }
        }
        return ans;
    }
};