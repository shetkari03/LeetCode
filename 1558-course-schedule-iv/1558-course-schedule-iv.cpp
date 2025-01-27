class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>ind(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            ind[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>grid(numCourses,vector<int>(numCourses,0));
        for(int i=0;i<numCourses;i++){
            queue<int>q;
            q.push(i);
            vector<int>vis(numCourses,0);
            vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                    grid[i][it]=1;
                }
            }
        }
        }
        vector<bool>ans;
        for(auto it:queries){
            ans.push_back(grid[it[0]][it[1]]);
        }
        return ans;
    }
};