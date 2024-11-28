class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        queue<pair<pair<int,int>,int>>q;//{node,dis}
        if(grid[0][0]==1){
            q.push({{0,0},1});
            dis[0][0]=1;
        }
        else{
            q.push({{0,0},0});
            dis[0][0]=0;
        }
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int r=q.front().first.first;
                int c=q.front().first.second;
                int d=q.front().second;
                q.pop();
                if(dis[r][c]<d)continue;
                //cout<<r<<" "
                for(int p=0;p<4;p++){
                    int nr=r+row[p],nc=c+col[p];
                    if(nr>=0 && nr<n && nc>=0 && nc<m ){
                        if(grid[nr][nc]==0 && dis[nr][nc]>d){
                            dis[nr][nc]=d;
                            q.push({{nr,nc},d});
                        }
                        else if(grid[nr][nc]==1 && dis[nr][nc]>d+1){
                            dis[nr][nc]=d+1;
                            q.push({{nr,nc},d+1});
                        }
                    }
                }
            }
        }
        // for(auto it:dis){
        //     for(auto t:it)cout<<t<<" ";
        //     cout<<endl;
        // }
        return dis[n-1][m-1];
    }
};