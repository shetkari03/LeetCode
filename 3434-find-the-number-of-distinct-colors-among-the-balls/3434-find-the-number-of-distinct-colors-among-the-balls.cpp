class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mpp,arr;
        vector<int>result;
        long long int ans=0;
        for(auto it:queries){
            int b=it[0],c=it[1];
            if(arr[mpp[b]]==1)ans--;
            arr[mpp[b]]--;
            if(arr[c]==0)ans++;
            arr[c]++;
            mpp[b]=c;
            result.push_back(ans);
        }
        return result;
    }
};