class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>arr(n,0);
        for(auto it:edges){
            arr[it[1]]++;
        }
        int ct=0,win=-1;
        for(int i=0;i<n;i++)
            if(arr[i]==0){
                ct++;
                win=i;
            }
        return ct==1?win:-1;
    }
};