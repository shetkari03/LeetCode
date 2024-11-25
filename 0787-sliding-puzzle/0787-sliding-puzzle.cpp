class Solution {
public:
string check(vector<vector<int>>&board){
    string s;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            s.push_back(board[i][j]+'0');
        }
    }
    return s;
}
int dfs(vector<vector<int>>&board,int i,int j,int ct,map<string,int>&mpp){
    string s=check(board);
    if(s=="123450"){
        return ct;
    }
    mpp[s]=ct;
    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    int ans=INT_MAX;
    for(int k=0;k<4;k++){
        int nr=i+row[k],nc=j+col[k];
        if(nr>=0 && nr<2 && nc>=0 && nc<3){
            swap(board[i][j],board[nr][nc]);
             s=check(board);
            if(mpp.find(s)!=mpp.end() && mpp[s]>ct+1){
                mpp[s]=ct+1;
                int d=dfs(board,nr,nc,ct+1,mpp);
                ans=min(ans,d);
            }
            else if(mpp.find(s)==mpp.end()){
                int d=dfs(board,nr,nc,ct+1,mpp);
                ans=min(ans,d);
            }
            swap(board[i][j],board[nr][nc]);
        }
    }
    return ans;
}
    int slidingPuzzle(vector<vector<int>>& board) {
        map<string,int>mpp;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    int d=dfs(board,i,j,0,mpp);
                    if(d==INT_MAX)return -1;
                    return d;
                }
            }
        }
        return -1;
    }
};