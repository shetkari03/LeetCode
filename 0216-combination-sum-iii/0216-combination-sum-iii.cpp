class Solution {
public:
void sol(int n,int sum,int cur,int k,vector<int>&temp,vector<vector<int>>&ans){
    if(sum==n){
        if(k==temp.size())ans.push_back(temp);
        return;
    }
    if(cur==10 || sum+cur>n)return;
    temp.push_back(cur);
    sol(n,sum+cur,cur+1,k,temp,ans);
    temp.pop_back();
    sol(n,sum,cur+1,k,temp,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        sol(n,0,1,k,temp,ans);
        return ans;
    }
};