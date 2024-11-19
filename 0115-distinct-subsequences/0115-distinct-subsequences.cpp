class Solution {
public:
    
    int numDistinct(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<double>dp(m+1,0),cur(m+1,0);
        dp[0]=1;
        double prev=1;
        for(int i=1;i<=n;i++){
            prev=1;
            for(int j=1;j<=m;j++){
                double k=dp[j];
                if(text1[i-1]==text2[j-1]){
                    dp[j]=prev+dp[j];
                }
                else{
                    dp[j]=k;
                }
                prev=k;
            }
        }
        return (int)(dp[m]);
    }
};