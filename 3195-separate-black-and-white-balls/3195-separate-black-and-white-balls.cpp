class Solution {
public:
    long long minimumSteps(string s) {
        long long int b=0,w=0,n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=(i-b);
                b++;
            }
        }
        return ans;
    }
};