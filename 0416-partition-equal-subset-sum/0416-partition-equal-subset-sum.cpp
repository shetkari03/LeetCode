class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum=sum+it;
        if(sum%2)return false;
        int target=sum/2;
        vector<bool>prev(target+1,false),cur(target+1,false);
        prev[0]=cur[0]=true;
        for(int i=1;i<nums.size();i++){
            prev[0]=cur[0]=true;
            for(int j=1;j<=target;j++){
                bool take=false;
                bool nontake=prev[j];
                if(nums[i]<=j)take=prev[j-nums[i]];
                cur[j]=take | nontake;
            }
            prev=cur;
        }
        return prev[target];
    }
};