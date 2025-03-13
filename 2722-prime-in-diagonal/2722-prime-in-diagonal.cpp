class preCompute{
    public:
        vector<bool>arr;
        preCompute(){
            int n=4*1000000+1;
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
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(obj.isPrime(nums[i][i])){
                ans=max(ans,nums[i][i]);
            }
            if(obj.isPrime(nums[i][n-1-i])){
                ans=max(ans,nums[i][n-1-i]);
            }
        }
        return ans;
    }
};