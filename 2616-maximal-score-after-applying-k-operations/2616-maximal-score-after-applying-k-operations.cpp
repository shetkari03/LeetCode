class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums)pq.push(it);
        long long ans=0;
        while(!pq.empty() && k){
            int d=pq.top();
            pq.pop();
            ans+=d;
            d=(d+2)/3;
            pq.push(d);
            k--;
        }
        return ans;
    }
};