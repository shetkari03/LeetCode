class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0]>1 && grid[0][1]>1)  return -1;
        int n=grid.size(),m=grid[0].size(),ans=INT_MAX;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};
        while(!pq.empty()){
            int r=pq.top()[1];
            int c=pq.top()[2];
            int d=pq.top()[0];
            pq.pop();
            if(r==n-1 && c==m-1)return d;
            for(int i=0;i<4;i++){
                int nr=r+row[i],nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int a=grid[nr][nc]-d;
                    if(a<0)a=0;
                    else a=1-a%2;
                    int t=max(d+1,grid[nr][nc]+a);
                    if(dis[nr][nc]>t){
                        dis[nr][nc]=t;
                        pq.push({t,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};