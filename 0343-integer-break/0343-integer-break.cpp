class Solution {
public:
    int integerBreak(int n) {
        vector<long long int>dp(n+1,0);
        for(int i=2;i<=n;i++)dp[i]=i-1;
        if(n==2)return 1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            long long int a=i-2,b=2;
            while(a>=b){
                long long int d=max(dp[a],a);
                d=d*(max(dp[b],b));
                dp[i]=dp[i]>d?dp[i]:d;
                a--;
                b++;
            }
        }
        return dp[n];
    }
};