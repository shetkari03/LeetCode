class Solution {
public:
long long int reversee(long long int n){
    long long int m=0;
    while(n)
    {
        m=m*10+n%10;
        n=n/10;
    }
    return m;
}
    int countNicePairs(vector<int>& nums) {
        map<long long int,long long int>mpp;
        long long int m=1e9+7;
        cout<<nums.size()<<endl;
        long long int ans=0;
        for(auto it:nums){
            long long int n=it,rev=reversee(it);
            ans+=mpp[n-rev];
            mpp[n-rev]++;
        }
        return ans%m;
    }
};