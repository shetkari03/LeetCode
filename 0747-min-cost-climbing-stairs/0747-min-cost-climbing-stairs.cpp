class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp=cost;
        //dp[0]=co;dp[1]=cost[1];
        cost[0]=0;
        for(int i=2;i<n;i++){
            int d=min(dp[i-1],dp[i-2]);
            dp[i]+=d;
        }
        for(auto it:dp)cout<<it<<" ";
        return min(dp[n-1],dp[n-2]);
    }
};