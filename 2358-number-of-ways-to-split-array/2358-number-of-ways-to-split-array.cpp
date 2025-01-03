class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(auto it:nums)sum+=it;
        long long t=0;
        int ans=0;
        for(auto it:nums){
            t+=it;
            sum-=it;
            if(sum<=t)ans++;
        }
        if(sum<=t)ans--;
        return ans;
    }
};