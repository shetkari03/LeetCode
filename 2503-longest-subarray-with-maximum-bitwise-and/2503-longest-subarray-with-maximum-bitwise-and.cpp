class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max=0;
        for(auto it:nums)max=max>it?max:it;
        int ans=0,ct=0;
        for(auto it:nums){
            if(it==max){
                ct++;
            }
            else{
                ct=0;
            }
            
                ans=ans>ct?ans:ct;
        }
        return ans;
    }
};