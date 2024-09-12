class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int hash[26]={0};
        for(auto it:allowed){
            hash[it-'a']=1;
        }
        int ans=0;
        for(auto it:words){
            bool flag=1;
            for(auto t:it){
                if(hash[t-'a']==0){
                    flag=0;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};