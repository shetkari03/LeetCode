class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>ans(n, vector<int>(m, 0));
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,pair<int,int>>>q;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int step = front.first;
            int row = front.second.first;
            int col = front.second.second;
            ans[row][col] = step;

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({step+1,{nrow,ncol}});
                }
            }
        }

        return ans;
    }
};