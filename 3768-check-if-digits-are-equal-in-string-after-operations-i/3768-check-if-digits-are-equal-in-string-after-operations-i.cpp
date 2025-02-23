class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string a;
        char prev=s[0];
        for(int i=1;i<s.size();i++){
            int d=prev-'0';
            int c=s[i]-'0';
            a.push_back((d+c)%10-'0');
            prev=c+'0';
        }
            s=a;
        }
        if(s.size()<2)return false;
        return s[0]==s[1];
    }
};