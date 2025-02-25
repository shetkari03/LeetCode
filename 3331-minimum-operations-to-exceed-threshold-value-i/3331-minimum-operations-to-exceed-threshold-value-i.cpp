class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ct=0;
        for(auto it:nums)if(it<k)ct++;
        return ct;
    }
};