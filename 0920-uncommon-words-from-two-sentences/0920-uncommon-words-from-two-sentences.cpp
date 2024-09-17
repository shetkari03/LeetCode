class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mpp;
        string s;
        for(auto it:s1){
            if(it==' '){
                mpp[s]++;
                s="";
            }
            else s.push_back(it);
        }
        mpp[s]++;
        s="";
        for(auto it:s2){
            if(it==' '){
                mpp[s]++;
                s="";
            }
            else s.push_back(it);
        }
        mpp[s]++;
        vector<string>ans;
        for(auto it:mpp){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;
    }
};