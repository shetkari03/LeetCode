class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int>dp(m+1,0);
        for(int i=1;i<=n;i++){
            int prev=dp[0];
            for(int j=1;j<=m;j++){
                int k=dp[j];
                if(text1[i-1]==text2[j-1]){
                    dp[j]=1+prev;
                }
                else{
                    dp[j]=dp[j]>dp[j-1]?dp[j]:dp[j-1];
                }
                prev=k;
            }
        }
        return dp[m];
        
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return longestCommonSubsequence(s,s1);
    }
};