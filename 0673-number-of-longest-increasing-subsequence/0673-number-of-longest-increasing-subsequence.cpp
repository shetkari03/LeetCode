class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1,ind=0;
        vector<int>dp(n,1);
        vector<int>arr(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]==dp[j]+1){
                        arr[i]=arr[j]+arr[i];
                    }
                    else if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        arr[i]=arr[j];
                    }
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
            }
        }
        for(int i=0;i<n;i++)if(dp[i]==ans)ind+=arr[i];
        return ind;
    }
};