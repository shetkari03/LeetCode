class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]-i]++;
        }
        long long int ans=0;
        for(auto it:mpp){
            n=n-it.second;
            ans=ans+(n*it.second);
        }
        return ans;
    }
};