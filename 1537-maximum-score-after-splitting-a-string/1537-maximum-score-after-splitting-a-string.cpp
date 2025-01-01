class Solution {
public:
    int maxScore(string s) {
        int one=0,zero=0,ans=0,n=s.size();
        for(auto it:s)if(it=='1')one++;
        if(one==0 || one==s.size())return s.size()-1;
        for(int i=0;i<n-1;i++){
            auto it=s[i];
            if(it=='0')zero++;
            if(it=='1')one--;
            ans=max(ans,zero+one);
        }
        return ans;
    }
};