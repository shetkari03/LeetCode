class Solution {
public:
    long long calculateScore(string s) {
        map<int,stack<int>>mpp;
        vector<char>t;
        for(int i=25;i>=0;i--)t.push_back(i);
        long long  ans=0;
        for(int i=0;i<s.size();i++){
            int d=s[i]-'a';
            if(mpp[t[d]].size()){
                int k=mpp[t[d]].top();
                mpp[t[d]].pop();
                ans+=i-k;
            }
            else{
                mpp[s[i]-'a'].push(i);
            }
        }
        return ans;
    }
};