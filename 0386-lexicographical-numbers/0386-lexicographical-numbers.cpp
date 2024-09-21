class Solution {
public:
void dfs(vector<int>&ans,int x,int n){
    if(x>n)return;
    ans.push_back(x);
    x=x*10;
    for(int i=0;i<=9;i++){
        dfs(ans,x+i,n);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            dfs(ans,i,n);
        }
        
        return ans;
    }
};