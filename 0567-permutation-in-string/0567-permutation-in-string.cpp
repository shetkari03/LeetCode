class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash[26]={0};
        if(s1.size()>s2.size())return 0;
        for(auto it:s1)hash[it-'a']++;
        int n=s2.size();
        int ct[26]={0};
        int i=0;
        while(i<s1.size()){
            ct[s2[i]-'a']++;
            i++;
        }
        int j=1;
        for(int k=0;k<26;k++)if(ct[k]!=hash[k])j=0;
        if(j==1)return 1;
        j=0;
        while(i<n){
            ct[s2[i]-'a']++;
            ct[s2[j]-'a']--;
            bool fl=1;
            for(int k=0;k<26;k++)if(ct[k]!=hash[k])fl=0;
            if(fl)return fl;
            i++;
            j++;
        }
        return 0;
    }
};