class Solution {
public:
    int minElement(vector<int>& nums) {
        int min=9999;
        for(auto it:nums){
            int d=it,sum=0;
            while(d){
                sum+=d%10;
                d=d/10;
            }
            min=min>sum?sum:min;
        }
        return min;
    }
};