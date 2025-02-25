class Solution {
public:
    int minSteps(string s, string t) {
        int hash[26]={0};
        for(int i=s.size()-1;i>=0;i--){
            hash[t[i]-'a']++;
            hash[s[i]-'a']--;
        }
        int ans=0;
        for(auto it:hash)if(it>0)ans+=it;
        return ans;
    }
};