class Solution {
public:
    bool check(vector<int>& nums) {
        int ct=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1])ct++;
        }
        if(nums[nums.size()-1]>nums[0])ct++;
        return ct<=1;
    }
};