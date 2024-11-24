class Solution {
public:
int sol(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<long>>>&dp){
    if(ind==prices.size() || cap==0)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    long  p=0;
    if(buy){
        p=max(-prices[ind]+sol(ind+1,0,cap,prices,dp),0+sol(ind+1,1,cap,prices,dp));
    }
    else{
        p=max(prices[ind]+sol(ind+1,1,cap-1,prices,dp),0+sol(ind+1,0,cap,prices,dp));
    }
    return dp[ind][buy][cap]=p;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0;
       // vector<vector<vector<long>>>dp(n+1,vector<vector<long>>(2,vector<long>(3,0)));
        vector<vector<long>>cur(2,vector<long>(3,0));
        vector<vector<long>>prev=cur;
        for(int i=n-1;i>=0;i--){
            prev=cur;
            for(int b=0;b<2;b++){
                for(int cap=1;cap<=2;cap++){
                    if(b){
                        cur[b][cap]=max(-prices[i]+prev[0][cap],prev[1][cap]);
                    }
                    else{
                        cur[b][cap]=max(prices[i]+prev[1][cap-1],prev[0][cap]);
                    }

                }
            }
            //cur=prev;
        }
        return cur[1][2];
    }
};