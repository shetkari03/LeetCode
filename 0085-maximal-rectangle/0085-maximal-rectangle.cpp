class Solution {
public:
int sol(vector<vector<char>>& matrix,int i,int j,int ct){
    int d=matrix.size()-1;
    int c=j+ct;
    int ans=ct+1;
    int h=matrix[0].size()-1>j+ct?j+ct:matrix[0].size()-1;
    for(int k=i+1;k<matrix.size();k++){
        if(matrix[k][j]=='0')break;
        for(int l=j;l<=h;l++){
            if(matrix[k][l]=='0'){
                c=c>l-1?l-1:c;
                break;
            }
        }
        d=k;
        ans=ans>(d-i+1)*(c-j+1)?ans:(d-i+1)*(c-j+1);
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    int ct=0,k=j+1;
                    while(k<col && matrix[i][k]=='1'){
                        k++;
                        ct++;
                    }
                    int d=sol(matrix,i,j,ct);
                    ans=ans>d?ans:d;
                }
            }
        }
        return ans;
    }
};