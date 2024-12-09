class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long >dp(n,0);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            long long  skip=dp[i+1];
            long long  solved=questions[i][0];
            int ind=i+1+questions[i][1];
            if(ind<n)solved+=dp[ind];
            dp[i]=max(skip,solved);
        }
        //for(auto it:dp)cout<<it<<" ";
        return dp[0];
    }
};