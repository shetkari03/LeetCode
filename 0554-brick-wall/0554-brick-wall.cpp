class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        int m=0;
        for(auto it:wall[0])m+=it;
        map<long long int ,int>hash;
        for(auto it:wall){
            long long int sum=0;
            for(auto t:it){
                sum+=t;
                hash[sum]++;
            }
        }
        int ans=n;
        for(auto it:hash){
            if(it.first>0 && it.first<m){
                ans=min(ans,n-it.second);
            }
        }
        return ans;
    }
};