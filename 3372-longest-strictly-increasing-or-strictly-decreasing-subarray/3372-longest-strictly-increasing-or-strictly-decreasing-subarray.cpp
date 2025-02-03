class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int n=nums.size();
        int ans=1;
        int cta=1,ctd=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])cta++;
            else cta=1;
            if(nums[i]<nums[i-1])ctd++;
            else ctd=1;
            ans=max(ans,max(cta,ctd));
        }
        return ans;
    }
};