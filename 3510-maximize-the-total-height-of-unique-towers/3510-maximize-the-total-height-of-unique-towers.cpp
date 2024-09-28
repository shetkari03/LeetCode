class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        map<long long int,int>mpp;
        long long int ans=0;
        for(auto it:maximumHeight){
            mpp[-1*it]++;
            ans=ans>it?ans:it;
        }
        long long int ct=ans;
        ans=0;
        for(auto it:mpp){
            long long int a=it.first*-1,d=it.second;
            ct=ct>a?a:ct;
            if(ct-d<0)return -1;
            ans+=((ct*(ct+1))-((ct-d)*(ct-d+1)))/2;
            ct=ct-d;
        }
        return ans;
    }
};