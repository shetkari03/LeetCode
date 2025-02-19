class Solution {
public:
void dfs(int i,int n,int &ct,int k,char prev,string &s,string &ans){
    if(ct==k)return ;
    if(i==n){
        ct++;
        if(ct==k)ans=s;
        return ;
    }
    for(int j=0;j<=2;j++){
        if(prev!=j+'a'){
            s.push_back(j+'a');
            char f=prev;
            prev=j+'a';
            dfs(i+1,n,ct,k,prev,s,ans);
            s.pop_back();
            prev=f;
        }
    }
}
    string getHappyString(int n, int k) {
        string s,ans;
        int ct=0;
        char prev=' ';
        dfs(0,n,ct,k,prev,s,ans);
        return ans;
    }
};