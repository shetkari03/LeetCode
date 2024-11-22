class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int tar=image[sr][sc];
        if(tar==color)return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int  row[4]={0,-1,0,1};
        int col[4]={-1,0,+1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i],nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==tar){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
            
        }
        return image;
    }
};