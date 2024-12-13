class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)pq.push({nums[i],i});
        long long ct=0;
        vector<int>mark(n,0);
        while(!pq.empty()){
            int d=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(mark[ind])continue;
            ct+=d;
            mark[ind]=1;
            if(ind>0)mark[ind-1]=1;
            if(ind<n-1)mark[ind+1]=1;
        }
        return ct;
    }
};