class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),i=0;
        for(auto it:t){
            if(i<n && s[i]==it)i++;
        }
        return i==n;
    }
};