class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<26;i++){
            char ch='a'+i;
            int st=-1,end=-1;
            int hash[26]={0};
            for(int j=0;j<n;j++){
                if(st!=-1)hash[s[j]-'a']++;
                if(st==-1 && ch==s[j])st=j;
                if(s[j]==ch)end=j;
            }
                int ct=0;
            if(st+2<=end){
                for(int j=end;j<n;j++)hash[s[j]-'a']--;
                for(auto it:hash)if(it)ct++;
                ans+=ct;
            }
        }
        return ans;
    }
};