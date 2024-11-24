class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,n=s.size();
        for(char ch='A';ch<='Z';ch++){
            int left=0,nt=0,ct=0;
            for(int i=0;i<n;i++){
                if(s[i]==ch)ct++;
                else nt++;
                while(nt>k && left<i){
                    if(s[left]==ch)ct--;
                    else nt--;
                    left++;
                }
                ans=max(ans,i-left+1);
            }
        }
        return ans;
    }
};