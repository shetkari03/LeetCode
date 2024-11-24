class Solution {
public:
int sol(int ind,int buy,vector<int>&prices,vector<vector<long>>&dp){
    if(ind>=prices.size())return 0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    long  p=0;
    if(buy){
        p=max(-prices[ind]+sol(ind+1,0,prices,dp),0+sol(ind+1,1,prices,dp));
    }
    else{
        p=max(prices[ind]+sol(ind+2,1,prices,dp),0+sol(ind+1,0,prices,dp));
    }
    return dp[ind][buy]=p;
}
    int maxProfit(vector<int>& prices) {
         int n=prices.size(),ans=0;
        vector<vector<long >>dp(n+1,vector<long >(2,-1));
        return sol(0,1,prices,dp);
    }
};