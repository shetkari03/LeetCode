class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size() )return false;
        int ct=0;
        int hash1[26]={0};
        int hash2[26]={0};
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=goal[i])ct++;
            hash1[s[i]-'a']++;
            hash2[goal[i]-'a']++;
        }
        int d=0,k=0;
        for(int i=0;i<26;i++){
            if(hash1[i]==hash2[i]){
                d++;
                if(hash1[i]>1)k++;
            }
        }
        if(d==26 ){
            if(ct==0 && k>0)return true;
            else if(ct==2 )return true;
            //return true;
        }
        return false;
    }
};