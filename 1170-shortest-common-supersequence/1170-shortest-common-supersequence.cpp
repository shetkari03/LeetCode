class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        int row=n,col=m;
        string s;
        while(row>0 && col>0){
            if(text1[row-1]==text2[col-1]){
                s.push_back(text1[row-1]);
                row--;col--;
            }
            else{
                if(dp[row-1][col]==dp[row][col]){
                    s.push_back(text1[row-1]);
                    row--;
                }
                else {
                    s.push_back(text2[col-1]);
                    col--;
                }
            }
        }
        col--;
        while(col>=0)s.push_back(text2[col--]);
        row--;
        while(row>=0)s.push_back(text1[row--]);
        reverse(s.begin(),s.end());
        return s;
    } 
    string shortestCommonSupersequence(string str1, string str2) {
        return longestCommonSubsequence(str1,str2);
    }
};