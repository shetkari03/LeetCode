class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i])dp[i]=dp[i]>1+dp[j]?dp[i]:1+dp[j];
            }
        }
        int ans=1;
        for(auto it:dp)ans=ans>it?ans:it;
        return ans;
    }
};