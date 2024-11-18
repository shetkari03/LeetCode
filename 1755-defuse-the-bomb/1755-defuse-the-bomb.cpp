class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>arr(code.size(),0);
        if(k==0){
            return arr;
        }
        bool f=false;
        if(k<0){
            reverse(code.begin(),code.end());
            k=k*-1;
            f=true;
        }
        int left=1,right=0,n=code.size(),sum=0;
        for(int i=1;i<=k;i++){right++;sum+=code[right];}
        for(int i=0;i<n;i++){
            arr[i]=sum;
            sum-=code[left];
            left=(left+1)%n;
            right=(right+1)%n;
            sum+=code[right];
        }
        if(f)reverse(arr.begin(),arr.end());
        return arr;
    }
};