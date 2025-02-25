class Solution {
public:
    int minSteps(string s, string t) {
        int hash[26]={0};
        for(auto it:t)hash[it-'a']++;
        for(auto it:s)hash[it-'a']--;
        int ans=0;
        for(auto it:hash){
            if(it>0)ans+=it;
            else ans+=(it*-1);
        }
        return ans;
    }
};