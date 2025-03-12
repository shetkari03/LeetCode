class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a=0,b=0;
        for(auto it:nums){
            if(it>0)a++;
            else if(it<0)b++;
        }
        return a>b?a:b;
    }
};