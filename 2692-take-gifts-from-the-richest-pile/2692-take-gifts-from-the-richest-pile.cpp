class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto it:gifts)pq.push(it);
        while(k--){
            int d=pq.top();pq.pop();
            d= (floor)(sqrt(d));
            pq.push(d);
           // k--;
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};