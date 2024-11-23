class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                vis[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)if(vis[i]==0)q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int r=q.front();
            q.pop();
            for(auto it:adj[r]){
                vis[it]--;
                if(vis[it]==0)q.push(it);
            }
        }
        for(int i=0;i<n;i++)if(vis[i]==0)ans.push_back(i);
        return ans;
    }
};