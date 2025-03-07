class pre{
    public:
      vector<bool>arr;
      pre(){
        arr.resize(1000001,1);
        arr[0] =arr[1] = false;
        for (int i = 2; i * i <= 1000000; i++) {
            if (arr[i]) {
                for (int j = i * i; j <= 1000000; j += i)
                    arr[j] = false;
            }
        }
      }
      bool check(int i){
        return arr[i];
      }
};
class Solution {
public:
pre obj=pre();
    vector<int> closestPrimes(int left, int right) {
        vector<int>a={-1,-1};
        int prev=INT_MIN,ans=INT_MAX;
        for(int i=left;i<=right;i++){
            if(obj.check(i)){
                if(prev!=INT_MIN){
                    if(ans>i-prev){
                        a={prev,i};
                        ans=i-prev;
                    }
                }
                prev=i;
            }
        }
        return a;
    }
};