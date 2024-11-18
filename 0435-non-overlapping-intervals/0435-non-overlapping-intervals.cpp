class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:intervals)pq.push({it[1],it[0]});
        int ans=0,prev=pq.top().first;
        pq.pop();
        while(!pq.empty()){
            pair<int,int> cur=pq.top();pq.pop();
            if(prev<=cur.second){
                prev=cur.first;
            }
            else ans++;
        }
        return ans;
    }
};