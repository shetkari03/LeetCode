class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        int i=0,j=0;
        while(i<n && j<m){
            int a=str1[i]-'a';
            int b=str2[j]-'a';
            if((a+1)%26==b || a==b){
                j++;
            }
            i++;
        }
        return j==m;
    }
};