class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans1=0,ans2=0;
        int cta=1,ctd=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])cta++;
            else cta=1;
            if(nums[i]<nums[i-1])ctd++;
            else ctd=1;
            ans1=ans1>cta?ans1:cta;
            ans2=ans2>ctd?ans2:ctd;
        }
        ans1=ans1>cta?ans1:cta;
        ans2=ans2>ctd?ans2:ctd;
        ans1=ans1>ans2?ans1:ans2;
        return ans1;
    }
};