class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans[n];
        vector<int>arr;
        for(int i=0;i<n-1;i++)ans[i].push_back(i+1);
        for(auto it:queries){
            ans[it[0]].push_back(it[1]);
            int ct=0;
            vector<int>vis(n,0);
            queue<pair<int,int>>q;
            q.push({0,0});
            vis[0]=1;
            while(!q.empty()){
                int m=q.size();
                for(int i=0;i<m;i++){
                    int node=q.front().first;
                    int d=q.front().second;
                    q.pop();
                    if(node==n-1){
                        arr.push_back(d);
                        break;
                    }
                    for(auto it:ans[node]){
                        if(vis[it]==0){
                            vis[it]=1;
                            q.push({it,d+1});
                        }
                    }
                }
            }
        }
        return arr;
    }
};