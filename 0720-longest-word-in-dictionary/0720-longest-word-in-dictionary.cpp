class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        map<string,int>mpp;
        string ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            int j=0,m=words[i].size();
            string t;
            while(j<m){
                t.push_back(words[i][j]);
                if(mpp.find(t)==mpp.end())break;
                j++;
            }
            cout<<i<<" "<<j<<endl;
            if(j==m-1){
                if(ans.size()==m){
                    if(ans>words[i])ans=words[i];
                }
                else if(ans.size()<m)ans=words[i];
            }
            mpp[words[i]]++;
        }
        return ans;
    }
};