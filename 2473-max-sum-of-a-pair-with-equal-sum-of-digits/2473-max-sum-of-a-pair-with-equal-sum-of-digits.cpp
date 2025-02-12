class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<pair<int,int>>pq;
        for(auto it:nums){
            int s=0,d=it;
            while(d){
                s+=d%10;
                d=d/10;
            }
            //cout<<s<<" "<<d<<endl;
            pq.push({s,it});
        }
        int prev=-1,k=-1;
        int ans=-1;
        while(!pq.empty()){
            int sum=pq.top().first;
            int n=pq.top().second;
            pq.pop();
            if(prev==sum){
                ans=max(ans,n+k);
            }
            //cout<<prev<<" "<<k<<endl;
            prev=sum;
            k=n;
        }
        return ans;
    }
};