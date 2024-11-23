class Solution {
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int sol(int n){
        int m=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)m++;
            cout<<i<<" "<<parent[i]<<endl;
        }
        return m;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ct=0;
        //vector<int>vis(n,0);
        //cout<<ct<<endl;
        for(auto it:connections){
            int x=it[0],y=it[1];
            if(ds.findUPar(x)!=ds.findUPar(y)){
               // vis[x]=1;
              // vis[y]=1;
                ds.unionByRank(x,y);
            }
            else ct++;
        }
        int m=ds.sol(n);
       // for(auto it:vis)if(it==0)m++;
       m--;
       // cout<<ct<<" "<<m<<endl;
        if(ct>=m)return m;
        return -1;
    }
};