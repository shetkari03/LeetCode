class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
        for(auto it:nums){
            pq.push(it);
        }
        int ans=0;
        while(pq.top()<k){
            ans++;
            long long int x=pq.top();pq.pop();
            long long int y=pq.top();pq.pop();
            pq.push(x*2+y);
        }
        return ans;
    }
};