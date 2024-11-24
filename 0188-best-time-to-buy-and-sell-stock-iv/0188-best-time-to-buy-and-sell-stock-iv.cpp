class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size(),ans=0;
        vector<vector<long>>cur(2,vector<long>(k+1,0));
        vector<vector<long>>prev=cur;
        for(int i=n-1;i>=0;i--){
            prev=cur;
            for(int b=0;b<2;b++){
                for(int cap=1;cap<=k;cap++){
                    if(b){
                        cur[b][cap]=max(-prices[i]+prev[0][cap],prev[1][cap]);
                    }
                    else{
                        cur[b][cap]=max(prices[i]+prev[1][cap-1],prev[0][cap]);
                    }

                }
            }
            //cur=prev;
        }
        return cur[1][k];
    }
};