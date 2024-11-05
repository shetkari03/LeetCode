class Solution {
public:
    int minChanges(string s) {
        int ct=0,prev=-1;
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            int d=s[i]-'0';
            if(prev==-1){
                ct=1;
                prev=s[i]-'0';
                continue;
            }
            if(d!=prev){
                if(ct%2!=0){
                    ans++;
                    ct=0;
                }
                else {
                    prev=d;
                    ct=1;
                }
            }
            else ct++;
        }
        return ans;
    }
};