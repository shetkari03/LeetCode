class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int ct=0;
        char prev='/';
        for(auto it:s){
            if(it==prev){
                ct++;
                if(ct<3)ans.push_back(it);
            }
            else {
                ct=1;
                ans.push_back(it);
            }
            prev=it;
        }
        return ans;
    }
};