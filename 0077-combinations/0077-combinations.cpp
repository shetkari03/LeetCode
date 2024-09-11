class Solution {
public:
void sol(int n,int i,int k,vector<int>&t,vector<vector<int>>&ans){
    if(t.size()==k){
        ans.push_back(t);
        return;
    }
    if(i>n || t.size()>k)return;
    sol(n,i+1,k,t,ans);
    t.push_back(i);
    sol(n,i+1,k,t,ans);
    t.pop_back();
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>t;
        sol(n,1,k,t,ans);
        return ans;
    }
};