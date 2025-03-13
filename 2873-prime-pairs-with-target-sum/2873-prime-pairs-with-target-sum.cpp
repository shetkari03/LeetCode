class preCompute{
    public:
        vector<bool>arr;
        preCompute(){
            int n=1000001;
            arr.resize(n,true);
            arr[1]=false;
            for (int p = 2; p * p <= n; p++) {
                if (arr[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    arr[i] = false;
                }
            
            }
        }
        bool isPrime(int m){
            return arr[m];
        }
};
class Solution {
public:
preCompute obj=preCompute();
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        int m=n/2;
        for(int i=2;i<=m;i++){
            if(obj.isPrime(i) && obj.isPrime(n-i)){
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};