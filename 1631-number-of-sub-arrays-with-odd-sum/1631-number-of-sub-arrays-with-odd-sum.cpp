class Solution {
public:
    const int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size(),fin=0;
        vector<int> ans(n);
        ans[n-1]=(arr[n-1]%2==0)?0:1;
        for(int i=n-2;i>=0;i--) ans[i]=(arr[i]%2==0)?ans[i+1]:1+((n-i-1)-ans[i+1]);
        for(auto i:ans) fin=(fin+i)%mod;
        return fin;
    }
};