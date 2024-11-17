class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),ans=INT_MAX,right=0;
        long long int sum=0;
        if(n==1){
            if(nums[0]>=k)return 1;
            return -1;
        }
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        while(right<n){
            sum+=nums[right];
            if(sum>=k)ans=ans>right+1?right+1:ans;       
            long long int a=0,b=-1,d=sum-k;
            while(!pq.empty() && d>=pq.top().first){
                int x=pq.top().first,y=pq.top().second;
                // if(sum>=k && d<x)break;
                // if(sum<k && d<x)break;
                if(b<y){
                    b=y;
                    a=x;
                }
                pq.pop();
            }
            if(sum-a>=k)ans=ans>right-b?right-b:ans;
            pq.push({sum,right});
            right++;
        }
        if(sum>=k)ans=ans>right?right:ans;
        return ans==INT_MAX?-1:ans;
    }
};