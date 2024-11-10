class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<INT_MAX;i++){
            int d=i,a=1;
            while(d){
                a=a*(d%10);
                d=d/10;
            }
            if(a%t==0)return i;
        }
        return n;
    }
};