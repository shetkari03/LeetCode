class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long int sum=0;
        for(auto it:nums)sum+=it;
        int n=nums.size();
        long long s=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            s+=nums[i];
            sum-=nums[i];
            if(abs(sum-s)%2==0)ans++;
        }
        return ans;
    }
};