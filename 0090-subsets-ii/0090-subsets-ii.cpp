class Solution {
public:
void sol(vector<int>&nums,int idx,vector<int>t,vector<vector<int>>&ans){
    ans.push_back(t);
    for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1])continue;
            t.push_back(nums[i]);
            sol(nums,i+1,t,ans);
            t.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>t;
        vector<vector<int>>ans;
        sol(nums,0,t,ans);
        return ans;
    }
};