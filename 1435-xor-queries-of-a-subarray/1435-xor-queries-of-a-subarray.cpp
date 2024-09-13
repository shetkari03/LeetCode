class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        map<int,int>mpp;
        int xr=0;
        for(int i=0;i<arr.size();i++){
            xr=xr^arr[i];
            mpp[i]=xr;
        }
        vector<int>ans;
        for(auto it:queries){
            int left=it[0],right=it[1];
            ans.push_back(mpp[right]^mpp[left-1]);
        }
        return ans;
    }
};