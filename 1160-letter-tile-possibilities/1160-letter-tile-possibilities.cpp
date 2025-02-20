class Solution {
public:
void  dfs(int n,string tiles,string s,unordered_map<string,int>&st,vector<int>&arr){
    bool f=true;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            f=false;
            arr[i]=1;
            dfs(n,tiles,s,st,arr);
            dfs(n,tiles,s+tiles[i],st,arr);
            arr[i]=0;
        }
    }
    if(f){
        if(s.size())st[s]++;
    }

}
    int numTilePossibilities(string tiles) {
        unordered_map<string,int>st;
        int n=tiles.size();
        vector<int>arr(n,0);
        dfs(n,tiles,"",st,arr);
        return st.size();
    }
};