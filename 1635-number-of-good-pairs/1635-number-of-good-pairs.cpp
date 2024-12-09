class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hash[101]={0};
        int ans=0;
        for(auto it:nums){
            ans+=hash[it];
            hash[it]++;
        }
        return ans;
    }
};