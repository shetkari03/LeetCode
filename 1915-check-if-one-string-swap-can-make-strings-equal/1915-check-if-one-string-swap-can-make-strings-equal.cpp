class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ct=0;
        int hash[26]={0};
        for(int i=s1.size()-1;i>=0;i--){
            if(s1[i]!=s2[i])ct++;
            hash[s1[i]-'a']++;
            hash[s2[i]-'a']--;
        }
        int d=0;
        for(auto it:hash)if(!it)d++;
        if(d==26 && (ct==0 || ct==2))return true;
        return false;
    }
};