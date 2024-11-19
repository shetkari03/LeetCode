class Solution {
public:
    int minDistance(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int>dp(m+1,0),cur(m+1,0);
        for(int i=0;i<=m;i++)dp[i]=i;
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    cur[j]=dp[j-1];
                }
                else{
                    int d=1+dp[j-1];
                    d=min(d,min(1+dp[j],1+cur[j-1]));
                    cur[j]=d;
                }
            }
            dp=cur;
        }
        return dp[m];
    }
};