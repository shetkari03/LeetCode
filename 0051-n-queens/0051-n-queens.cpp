class Solution {
public:
void func(int col,int n,vector<int>&row,vector<int>&lower,vector<int>&upper,
vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(row[i]==0 && lower[i+col]==0 && upper[n-1+col-i]==0){
            row[i]=1;upper[n-1+col-i]=1;lower[i+col]=1;
            board[i][col]='Q';
            func(col+1,n,row,lower,upper,board,ans);
            row[i]=0;upper[n-1+col-i]=0;lower[i+col]=0;
            board[i][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        vector<int>row(n,0),lower(2*n-1,0),upper(2*n-1);
        func(0,n,row,lower,upper,board,ans);
        return ans;
    }
};