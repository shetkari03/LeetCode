class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        map<string,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s.substr(0,i+1)]++;
        }
        int ans=0;
        for(auto it:words){
            ans+=mpp[it];
        }
        return ans;
    }
};