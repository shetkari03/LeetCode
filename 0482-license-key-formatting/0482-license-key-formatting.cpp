class Solution {
public:
bool islower(char ch){
    int d=ch-'a';
    if(d>=0 && d<=25)return true;
    return false;
}
char to_upper(char ch){
    int d=ch-'a';
    return 'A'+d;
}
    string licenseKeyFormatting(string s, int k) {
        string temp;
        int n=s.size(),ct=0;
        for(int i=n-1;i>=0;i--){
            char it=s[i];
            if(it=='-')continue;
            if( islower(it)){
                temp.push_back(to_upper(it));
            }
            else temp.push_back(it);
            ct++;
            if(ct==k && i>0){
                temp.push_back('-');
                ct=0;
            }         
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]=='-')temp.pop_back();
            else break;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};