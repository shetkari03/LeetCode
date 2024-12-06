class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int>arr(n+1,1);
        for(auto it:banned)if(it<=n)arr[it]=0;
        int sum=0,ct=0;
        for(int i=1;i<=n;i++){
            if(sum+i>maxSum)break;
            if(arr[i]==1){sum+=i;ct++;}
        }
        return ct;
    }
};