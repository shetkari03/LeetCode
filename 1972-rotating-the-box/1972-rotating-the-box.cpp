class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            int j=m-1,k=m-1;
            while(j>=0){
                if(box[i][j]=='*'){
                    ans[j][n-i-1]='*';
                    k=j-1;
                }
                else if(box[i][j]=='#'){
                    ans[k][n-1-i]='#';
                    k--;
                }
                j--;
            }
        }
        return ans;
    }
};