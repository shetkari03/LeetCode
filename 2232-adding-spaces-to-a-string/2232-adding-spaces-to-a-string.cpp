class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int i=0,n=spaces.size();
        for(int j=0;j<s.size();j++){
            if(i<n && spaces[i]==j){
                ans.push_back(' ');
                i++;
            }
            ans.push_back(s[j]);
        }
        return ans;
    }
};