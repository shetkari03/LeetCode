class Solution {
public:
int sol(int ind,int buy,int fee,vector<int>&prices,vector<vector<long>>&dp){
    if(ind>=prices.size())return 0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    long  p=0;
    if(buy){
        p=max(-prices[ind]+sol(ind+1,0,fee,prices,dp),0+sol(ind+1,1,fee,prices,dp));
    }
    else{
        p=max(prices[ind]-fee+sol(ind+1,1,fee,prices,dp),0+sol(ind+1,0,fee,prices,dp));
    }
    return dp[ind][buy]=p;
}
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size(),ans=0;
        //vector<vector<long >>dp(n+2,vector<long >(2,-1));
        //return sol(0,1,fee,prices,dp);
         vector<vector<long >>dp(n+2,vector<long >(2,0));
        //return sol(0,1,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                if(b){
                    dp[i][b]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][b]=max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
                }
            }
        }
        //cout<<dp[0][0]<<" "<<dp[0][1]<<endl;
        return dp[0][1];
    }
};