class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0,n=s.size(),k=0;
        string prev="";
        for(auto it:words){
            if(it.size()>s.size())continue;
            if(prev==it){
                if(k)ans++;
                continue;
            }
            k=0;
            int i=0,m=it.size();
            for(auto t:s){
                if(i<m && it[i]==t)i++;
            }
            if(i==m){
                ans++;
                k=1;
            }
            prev=it;
        }
        return ans;
    }
};