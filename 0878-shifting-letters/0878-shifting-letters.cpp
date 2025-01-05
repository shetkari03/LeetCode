class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        int a=0;
        for(int i=n-1;i>=0;i--){
            a+=shifts[i];
            a=a%26;
            int d=s[i]-'a';
            d=d+a;
            d=d%26;
            s[i]=d+'a';
        }
        return s;
    }
};