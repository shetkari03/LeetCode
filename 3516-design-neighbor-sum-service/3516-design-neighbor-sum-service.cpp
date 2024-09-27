class NeighborSum {
public:
vector<vector<int>>grid;
    NeighborSum(vector<vector<int>>& grd) {
        grid=grd;
    }
    
    int adjacentSum(int value) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=value)continue;
                int ar[5]={0};
                int ct=1;
                if(i>0 )ar[ct++]+=grid[i-1][j]+ar[ct-1];
                if(j>0)ar[ct++]+=grid[i][j-1]+ar[ct-1];
                if(i<n-1)ar[ct++]+=grid[i+1][j]+ar[ct-1];
                if(j<n-1)ar[ct++]+=grid[i][j+1]+ar[ct-1];
                return ar[ct-1];
            }
        }
        return 0;
    }
    
    int diagonalSum(int value) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=value)continue;
                int ar[5]={0};
                int ct=1;
                if(i>0 && j>0)ar[ct++]+=grid[i-1][j-1]+ar[ct-1];
                if(i<n-1 && j>0)ar[ct++]+=grid[i+1][j-1]+ar[ct-1];
                if(i<n-1 && j<n-1)ar[ct++]+=grid[i+1][j+1]+ar[ct-1];
                if(j<n-1 && i>0)ar[ct++]+=grid[i-1][j+1]+ar[ct-1];
                return ar[ct-1];
            }
        }
        return 0;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */