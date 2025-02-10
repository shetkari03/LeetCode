class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(auto it:s){
            int d=it-'0';
            if(d>=0 && d<=9)ans.pop_back();
            else ans.push_back(it);
        }
        return ans;
    }
};