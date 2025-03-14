class Solution {
public:
long long check(vector<int>& candies,int mid){
    long long  ct=0;
    long long sum=0;
    for(auto it:candies){
        ct+=it/mid;
    }
    return ct;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(candies,mid)>=k){
                ans=max(ans,mid);
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};