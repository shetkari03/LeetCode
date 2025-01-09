class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0,n=pref.size();
        for(auto it:words){
            int m=it.size();
            if(n>m)continue;
            int i=0;
            while(i<n){
                if(pref[i]!=it[i])break;
                i++;
            }
            if(i==n)ans++;
        }
        return ans;
    }
};