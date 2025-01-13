class Solution {
public:
    int minimumLength(string s) {
        int hash[26]={0};
        for(auto it:s)hash[it-'a']++;
        int ans=0;
        for(auto it:hash){
            if(it==0)continue;
            ans+=(2-it%2);
        }
        return ans;
    }
};