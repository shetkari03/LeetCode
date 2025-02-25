class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        int hash[100001]={0};
        int vis[100001]={0};
        for(auto it:matches){
            vis[it[0]]=1;
            vis[it[1]]=1;
            hash[it[1]]++;
        }
        for(int i=1;i<=100000;i++){
            if(vis[i]){
                if(hash[i]==0)ans[0].push_back(i);
                if(hash[i]==1)ans[1].push_back(i);
            }
        }
        return ans;
    }
};