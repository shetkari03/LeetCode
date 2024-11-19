class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int m=0;
        for(auto it:nums)m=m>it?m:it;
        vector<int>hash(m+1,0);
        long long int left=0,right=0,sum=0,ans=0;
        while(right<n){
            hash[nums[right]]++;
            sum+=nums[right];
            while(hash[nums[right]]>1 && left<right){
                hash[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            while(right-left+1>k && left<right){
                hash[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            if(right-left+1==k)ans=ans>sum?ans:sum;
            right++;
        }
        return ans;
    }
};