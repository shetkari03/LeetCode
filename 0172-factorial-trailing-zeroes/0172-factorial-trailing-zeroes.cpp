class Solution {
public:
    int trailingZeroes(int n) {
        int a=0,b=0,ans=0;
        for(int i=1;i<=n;i++){
            int k=i;
            if(i%10==0){
                int d=k;
                while(d%10==0){
                    d=d/10;
                    ans++;
                }
                k=d;
            }
            if(k%5==0){
                int d=k;
                while(d%5==0){
                    b++;
                    d=d/5;
                }
            }
            else if(k%2==0){
                int d=k;
                while(d%2==0){
                    a++;
                    d=d/2;
                }
            }
        }
        a=a>b?b:a;
        ans+=a;
        return ans;
    }
};