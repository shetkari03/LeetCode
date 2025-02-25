class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int hash[61]={0};
        int ans=0;
        for(auto it:time){
            int d=60-it%60;
            ans+=hash[60-d];
            if(d==0 || d==60){
                hash[0]++;
                hash[60]++;
            }
            else hash[d]++;
        }
        return ans;
    }
};