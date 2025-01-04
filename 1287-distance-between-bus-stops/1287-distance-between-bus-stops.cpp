class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int x=start,a=0,ans=INT_MAX;
        int n=distance.size();
        while(x!=destination){
            a+=distance[x];
            x=(x+1)%n;
        }
        ans=a;
        x=destination,a=0;
        while(x!=start){
            a+=distance[x];
            x=(x+1)%n;
        }
        ans=min(a,ans);
        return ans;
    }
};