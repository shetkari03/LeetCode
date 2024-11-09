class Solution {
public:
    long long minEnd(int n, int x) {
        int d=x;
        string s;
        // while(d){
        //     if(d%2==0)s.push_back('0');
        //     d=d/2;
        // }
        // while(s.size()<=30)s.push_back('0');
        long long ans=0;
        // for(int i=1;i<n;i++){
        //     int add=1,car=1;
        //     for(int j=0;j<30;j++){
        //         if(s[j]=='1'){
        //             if(car==1){
        //                 s[j]='0';
        //             }
        //         }
        //         else{
        //             if(car==1){
        //                 s[j]='1';
        //                 car=0;
        //             }
        //         }
        //     }
        // }
        // int q=n-1;
        // int ct=1,k=1;
        // while(ct<n-1)ct=ct*(k++);
        int q=n-1;
        while(q){
            s.push_back(q%2+'0');
            q=q/2;
        }
        int i=0;
        d=x;
        string t;
        while(d){
            if(d%2==0)t.push_back(s[i++]);
            else t.push_back('1');
            d=d/2;
        }
        while(i<s.size())t.push_back(s[i++]);
        long long a=1;
        for(auto it:t){
            if(it=='1')ans+=a;
            a=a*2;
        }
        return ans;
    }
};