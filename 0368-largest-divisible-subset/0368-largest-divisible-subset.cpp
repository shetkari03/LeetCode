class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n,0);
        for(int i=0;i<n;i++)hash[i]=i;
        int ans=1,ind=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
                ind=i;
            }
        }
        vector<int>arr(ans,0);
            int  j=ans-1;
             while(hash[ind]!=ind && j>=0){
                 arr[j]=nums[ind];
                 ind=hash[ind];
                 j--;
             }
             arr[j]=nums[ind];
        return arr;
    }
};