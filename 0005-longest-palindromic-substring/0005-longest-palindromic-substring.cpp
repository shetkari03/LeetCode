class Solution {
    int check(string &s,int low,int high){
        int ct=0;
        while(low<high){
            if(s[low]!=s[high]){
                ct=-1;
                break;
            }
            low++;
            high--;
        }
        return ct;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size(),l=0,m=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int t=check(s,i,j);
                if(t==0){

                    if(ans<(j-i+1)){
                        l=i;
                        m=j;
                        ans=j-i+1;
                    }
                }
                
            }
        }
        return s.substr(l,m-l+1);
    }
};