class Solution {
public:
void dfs(vector<int>&nums,int i,int target,int sum,int &ans){
    if(i==nums.size()){
        if(sum==target)ans++;
        return;
    }
    //if(sum>target)return;
    dfs(nums,i+1,target,sum+nums[i],ans);
    dfs(nums,i+1,target,sum-nums[i],ans);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0,sum=0;
        dfs(nums,0,target,sum,ans);
        return ans;
    }
};