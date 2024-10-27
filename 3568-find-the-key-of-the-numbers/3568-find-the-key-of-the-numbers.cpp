class Solution {
public:
void rev(int& n){
    int ct=0,d=0;
    while(n){
        ct=ct*10+n%10;
        n=n/10;
        d++;
    }
    n=ct;
    while(d<4){
        d++;
        n=n*10;
    }
}
    int generateKey(int num1, int num2, int num3) {
        int ans=0;
        rev(num1);rev(num2);rev(num3);
        for(int i=0;i<4;i++){
            int d=num1%10;
            d=min(d,num2%10);
            d=min(d,num3%10);
            num1=num1/10;num2=num2/10;num3=num3/10;
            ans=ans*10+d;
        }
        return ans;
    }
};