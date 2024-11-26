class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int a=0,b=0,c=0;
        int left=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            if(s[i]=='b')b++;
            if(s[i]=='c')c++;
            while(a>=1 && b>=1 && c>=1 ){
                if(s[left]=='a')a--;
                if(s[left]=='b')b--;
                if(s[left]=='c')c--;
                left++;
                ans+=(n-i);
            }
        }
        return ans;
    }
};