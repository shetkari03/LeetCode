class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        int i=0;
        vector<string>ans;
        while(i<n){
            int ct=1,j=i+1,m=0;
            m+=words[i].size();
            while(j<n && m+words[j].size()<=maxWidth-1){
                ct++;
                m+=words[j].size();
                m++;
                j++;
            }
            int rem=maxWidth-m;
            if(ct==1){
                string s;
                for(int k=0;k<maxWidth;k++)s.push_back(' ');
                for(int k=0;k<words[i].size();k++)s[k]=words[i][k];
                i++;
                ans.push_back(s);
            }
            else{
                int space=rem/(ct-1);
                int r=rem%(ct-1);
                string s;
                while(ct--){
                    s=s+words[i]+' ';
                    for(int k=0;k<space;k++)s.push_back(' ');
                    if(r>0){
                        s.push_back(' ');
                        r--;
                    }
                   i++;
                }
                int p=s.size()-1;
                while(s[p]==' ' && p>=0){
                    s.pop_back();
                    p--;
                }
                ans.push_back(s);
            }
        }
        n=ans.size();
        string s;
        char prev='a';
        for(auto it:ans[n-1]){
            if(prev==' ' && it==' ')continue;
            s.push_back(it);
            prev=it;
        }
        while(s.size()<maxWidth)s.push_back(' ');
        ans[n-1]=s;
            return ans;
    }
};