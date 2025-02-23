class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                pq.push({grid[i][j],i});
            }
        }
        long long ans=0;
        int ct=0;
        while(!pq.empty() && ct!=k){
            int n=pq.top().first;
            int i=pq.top().second;
            pq.pop();
            if(limits[i]>0){
                limits[i]--;
                ans+=n;
                ct++;
            }
        }
        return ans;
    }
};