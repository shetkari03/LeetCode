class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=s.size(),i=0;
        for(auto it:words){
            int m=it.size();
            for(int j=0;j<m;j++){
                if(it[j]!=s[i])return false;
                i++;
                if(i==n && j==m-1)return true;
                if(i==n && j!=m-1)return false;
            }
        }
        return false;
    }
};