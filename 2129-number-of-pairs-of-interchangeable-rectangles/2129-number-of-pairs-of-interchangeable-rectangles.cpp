class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int>mpp;
        long long ans=0;
        for(auto it:rectangles){
            double a=it[0]*1.0,b=it[1]*1.0;
            double ratio=(double)(a/b);
            ans+=mpp[ratio];
            mpp[ratio]++;
        }
        return ans;
    }
};