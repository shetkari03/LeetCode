class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>vis(n*n,0);
        vector<int>arr(2,0);
        for(auto it:grid){
            for(auto t:it){
                vis[t-1]++;
                if(vis[t-1]==2)arr[0]=t;
            }
        }
        for(int i=0;i<n*n;i++)if(vis[i]==0){arr[1]=i+1;break;}
        return arr;
    }
};