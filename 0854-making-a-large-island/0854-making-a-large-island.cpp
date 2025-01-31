class DisjointSet{
    public:
    vector<int>parent,rank,size;
    DisjointSet(int n){
        parent.resize(n+1);rank.resize(n+1);size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
            size[i]=1;
        }
    }
    int findUparent(int i){
        if(i==parent[i])return i;
        return parent[i]=findUparent(parent[i]);
    }
    void unionBySize(int u,int v){
        int pu=findUparent(u),pv=findUparent(v);
        if(pu!=pv){
            if(size[pu]>=size[pv]){
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
    }
    void unionByRank(int u,int v){
        int pu=findUparent(u),pv=findUparent(v);
        if(pu!=pv){
            if(rank[pu]>=rank[pv]){
                parent[pv]=pu;
                rank[pu]++;
            }
            else{
                parent[pu]=pv;
                rank[pv]++;
            }
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        DisjointSet obj(n*n);
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                for(int k=0;k<4;k++){
                    int nr=i+row[k],nc=j+col[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        obj.unionBySize(n*i+j,n*nr+nc);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                set<int>par;
                for(int k=0;k<4;k++){
                    int nr=i+row[k],nc=j+col[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        par.insert(obj.findUparent(nr*n+nc));
                    }
                }
                int ct=1;
                for(auto it:par)ct+=obj.size[it];
                ans=ans>ct?ans:ct;
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            ans = max(ans, obj.size[obj.findUparent(cellNo)]);
        }
        return ans;
    }
};