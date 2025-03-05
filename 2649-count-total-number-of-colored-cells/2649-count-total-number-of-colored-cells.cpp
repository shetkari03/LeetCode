class pre{
    public:
        long long arr[100001]={0};
       pre(){
         long long a=4;
        arr[1]=1;
        for(int i=2;i<=100000;i++){
            arr[i]=arr[i-1]+a;
            a+=4;
        }    
       }
       long long gett(int i){
            return arr[i];
        }
};
class Solution {
public:
pre obj = pre();
    long long coloredCells(int n) {
        return obj.gett(n);
    }
};