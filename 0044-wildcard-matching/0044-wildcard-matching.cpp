class Solution {
public:
    bool isMatch(string text2, string text1) {
        int n=text1.size(),m=text2.size();
        //if(n>m)return 0;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        for(int i=1;i<=n;i++){
            if(text1[i-1]!='*')break;
            dp[i][0]=true;
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1] || text1[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(text1[i-1]=='*'){
                    bool d=dp[i-1][j-1];
                    dp[i][j]=d|dp[i-1][j]|dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        
            // for(int j=0;j<=m;j++){
            //     if(dp[n][j])return 1;
            // }
        return dp[n][m];
    }
};