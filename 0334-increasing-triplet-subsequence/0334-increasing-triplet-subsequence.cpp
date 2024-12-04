class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>arr;
        int m=INT_MAX;
        for(auto it:nums){
            arr.push_back(m);
            m=m>it?it:m;
        }
        m=nums[nums.size()-1];
        for(int i=nums.size()-2;i>0;i--){
            if(arr[i]<nums[i] && m>nums[i])return true;
            m=m>nums[i]?m:nums[i];
        }
        return false;
    }
};