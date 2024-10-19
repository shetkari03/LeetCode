class Solution {
public:
string sol(int n){
    if(n==1)return "0";
    string t=sol(n-1);
    t.push_back('1');
    int k=t.size()-1;
    for(int i=k-1;i>=0;i--){
        if(t[i]=='1')t.push_back('0');
        else t.push_back('1');
    }
   // cout<<n<<" "<<t<<endl;
    return t;
}
    char findKthBit(int n, int k) {
        string s=sol(n);
        return s[k-1];
    }
};