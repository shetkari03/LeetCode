class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>hash1,hash;
        for(auto it:t)hash1[it]++;
        int ct=26-hash1.size();
        int n=s.size(),ans=INT_MAX,i=0,j=0;
        for(int left=0,right=0;right<n;right++){
            hash[s[right]]++;
            if(hash[s[right]]==hash1[s[right]] && hash1[s[right]]!=0)ct++;
            while(ct==26 && left<right){
                hash[s[left]]--;
                if(ans>right-left+1){
                    ans=right-left+1;
                    i=right;
                    j=left;
                }
                if(hash[s[left]]<hash1[s[left]]){
                    left++;
                    ct--;
                    break;
                }
                left++;
            }if(ct==26 &&  ans>right-left+1){
                    ans=right-left+1;
                    i=right;
                    j=left;
                
            }
        }
        if(ans==INT_MAX)return "";
        string p;
        for(int k=j;k<=i;k++)p.push_back(s[k]);
        return p;
    }
};