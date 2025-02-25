class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long hash[25]={0};
        long long  ans=0;
        for(auto it:hours){
            int d=24-it%24;
            ans+=hash[24-d];
            if(d==0 || d==24){
                hash[0]++;
                hash[24]++;
            }
            else hash[d]++;
        }
        return ans;
    }
};