class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x=0;
        for(auto &it:nums1)x=(x^it);
        int y=0;
        for(auto &it:nums2)y=(y^it);
        int n=nums1.size();
        int m=nums2.size();
        if(n%2==0 and m%2==0)return 0;
        else if(n%2==0)return x;
        else if(m%2==0)return y;
        else return x^y;

    }
};