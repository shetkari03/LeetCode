class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            int n=s.size();
            for(int i=0;i<n;i++){
                int h=s[i]-'a';
                h++;
                h=h%26;
                s.push_back('a'+h);
            }
        }
        return s[k-1];
    }
};