class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0),suf(n,0);
        int m=nums[0],m2=INT_MAX;
        for(int i=0;i<n;i++){
            pre[i]=m;
            m=m>nums[i]?m:nums[i];
            suf[n-i-1]=m2;
            m2=m2<nums[n-i-1]?m2:nums[n-i-1];
            //pre.push_back(nums)
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(pre[i]<nums[i] && suf[i]>nums[i]){
                ans+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])ans++;
        }
        return ans;
    }
};