class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp={nums[0]};
        int size=1;
        for(int i=1;i<n;i++){
            if(dp[size-1]<nums[i]){
                dp.push_back(nums[i]);
                size++;
            }
            else {
                int left=0,right=size-1;
                while(left<=right){
                    int mid=(left+right)/2;
                    if(dp[mid]>=nums[i])right=mid-1;
                    else left=mid+1;
                }
                dp[left]=nums[i];
            }
            
        }
        return dp.size();
    }
};