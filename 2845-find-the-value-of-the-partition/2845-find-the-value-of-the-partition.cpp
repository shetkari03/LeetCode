class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int ans=INT_MAX;
        for(int i=1;i<n;i++)ans=ans>nums[i]-nums[i-1]?nums[i]-nums[i-1]:ans;
        return ans;
    }
};