class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long int >>graph(n,vector<long long int>(n,-1));
        for(auto it:edges){
            graph[it[0]][it[1]]=it[2];
            graph[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==-1)graph[i][j]=INT_MAX;
                if(i==j)graph[i][j]=0;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        int city=-1,ct=n;
        for(int i=0;i<n;i++){
            int b=0;
            for(int j=0;j<n;j++){
                if(i!=j && graph[i][j]<=distanceThreshold)b++;
            }
            if(b<=ct){
                city=i;
                ct=b;
            }
        }
        return city;
    }
};