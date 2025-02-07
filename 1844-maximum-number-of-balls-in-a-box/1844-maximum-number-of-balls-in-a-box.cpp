class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int hash[46]={0},ans=0;
        while(lowLimit<=highLimit){
            int n=lowLimit++;
            int ct=0;
            while(n){
                ct+=n%10;
                n=n/10;
            }
            hash[ct]++;
            ans=max(ans,hash[ct]);
        }
        return ans;

    }
};