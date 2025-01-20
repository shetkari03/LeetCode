class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>hash1(n,0),hash2(m,0);
        vector<pair<int,int>>mpp(n*m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            int r=mpp[arr[i]].first,c=mpp[arr[i]].second;
            hash1[r]++;
            if(hash1[r]==m)return i;
            hash2[c]++;
            if(hash2[c]==n)return i;
        }
        return -1;
    }
};