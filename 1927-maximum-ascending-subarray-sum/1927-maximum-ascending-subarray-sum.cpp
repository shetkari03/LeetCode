class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0,prev=0,ans=0;
        for(auto it:nums){
            if(prev<it){
                sum+=it;
            }
            else sum=it;
            ans=max(ans,sum);
            prev=it;
        }
        return ans;
    }
};