class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last=days.back();
        vector<int>  dp(last+1,0);
        int cur=0;


        for(int d=1;d<=last and cur<(int)days.size();d++){
            if(d<days[cur]){
                dp[d]=dp[d-1];
            }
            else{
                cur++;
                dp[d]=min({dp[d-1]+costs[0],dp[max(0,d-7)]+costs[1],dp[max(0,d-30)]+costs[2]});
            }
        }
        return dp[last];

    }
};