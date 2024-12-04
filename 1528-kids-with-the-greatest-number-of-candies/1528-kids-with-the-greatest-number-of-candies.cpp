class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=0;
        for(auto it:candies)m=m>it?m:it;
        vector<bool>res(candies.size(),false);
        int i=0;
        for(auto it:candies){
            if((it+extraCandies)>=m)res[i]=true;
            i++;
        }
        return res;
    }
};