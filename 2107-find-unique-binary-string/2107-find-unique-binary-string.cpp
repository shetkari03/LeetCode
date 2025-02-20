class Solution {
public:
void dfs(int i,int n,map<string,int>&mpp,string &s,string &ans){
    if(ans.size())return;
    if(i==n){
        if(mpp[s]==0)ans=s;
        return;
    }
    s.push_back('0');
    dfs(i+1,n,mpp,s,ans);
    s.pop_back();
    s.push_back('1');
    dfs(i+1,n,mpp,s,ans);
    s.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>mpp;
        for(auto it:nums)mpp[it]=1;
        string s;
        string ans;
        dfs(0,nums.size(),mpp,s,ans);
        return ans;
    }
};