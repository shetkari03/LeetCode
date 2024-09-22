class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>ans(r);
        int i=0,j=0;
        if(r*c!=mat.size()*mat[0].size())return mat;
        for(auto it:mat){
            for(auto t:it){
                ans[i].push_back(t);
                //i++;
                j++;
                if(j==c)i++;
                j=j%c;
            }
        }
        return ans;
    }
};