class Solution {
public:
    int isPrefixOfWord(string s, string s1) {
        int n=s.size(),m=s1.size();
        int i=0,j=0,k=0;
        while(i<n){
            if(s[i]!=' '){
                j=0;k++;
                while(i<n && j<m && s[i]!=' '){
                    if(s[i]!=s1[j])break;
                    i++;
                    j++;
                }
                while(i<n && s[i]!=' ')i++;
                if(j==m)return k;
            }
            i++;
        }
        return -1;
    }
};