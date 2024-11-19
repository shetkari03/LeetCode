class Solution {
public:
bool func(string s1,string s2){
    if(s1.size()<s2.size())return func(s2,s1);
    int i=0,j=0,n=s1.size(),m=s2.size();
    if(n-m!=1)return false;
    while(i<n && j<m){
        if(s2[j]==s1[i]){
            i++;
            j++;
        }
        else i++;
    }
    return j==m;
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](auto a,auto b){
            return a.size()<b.size();
        });
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(func(words[j],words[i]))dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int ans=0;
        for(auto it:dp)cout<<it<<" ";
        for(auto it:dp)ans=ans>it?ans:it;
        return ans;
    }
};