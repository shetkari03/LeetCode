class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<n;i++){
            if(pq.top()>=intervals[i][0])pq.push(intervals[i][1]);
            else{
                pq.push(intervals[i][1]);
                pq.pop();
            }
        }
        return pq.size();
    }
};