class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n=sentence.size();
        map<string,int>mpp;
        for(auto it:dictionary)mpp[it]++;
        string ans;
        for(int i=0;i<n;i++){
            string g;
            bool f=true;
            while(i<n && sentence[i]!=' '){
                g.push_back(sentence[i]);
                if(f)ans.push_back(sentence[i]);
                if(mpp[g])f=false;
                i++;
            }
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};