class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>>temp;
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,
          greater<pair<pair<int,int>,int>>>pq;
        for(int i=times.size()-1;i>=0;i--)pq.push({{times[i][0],times[i][1]},i});
        while(!pq.empty()){
            int arr=pq.top().first.first;
            int end=pq.top().first.second;
            int t=pq.top().second;
            int ind=-1,n=temp.size();
            for(int i=0;i<n;i++){
                if(temp[i].first<=arr){
                    ind=i;
                    break;
                }
            }
            if(ind==-1){
                temp.push_back({end,t});
                if(t==targetFriend)return  n;
            }
            else{
                temp[ind]={end,t};
                if(t==targetFriend)return ind;
            }
            pq.pop();
        }
        return 0;
    }
};