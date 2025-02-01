class Solution {
public:

    bool isArraySpecial(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]%2==nums[i+1]%2)return false;
        }
        return true;
    }
};