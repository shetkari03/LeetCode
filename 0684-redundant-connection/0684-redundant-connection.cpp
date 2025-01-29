class Solution {
public:
void setparent(vector<int>& parent,int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

//find_parent // path compression
int find_parent(int node,vector<int>& parent){
    if(parent[node] == node) return node;
    return parent[node] = find_parent(parent[node],parent);
}


//union
void makeunion(int x,int y,vector<int>& parent,vector<int>& rank){

    int u = find_parent(x,parent);
    int v = find_parent(y,parent);
    if(u==v) return;
    //rank speaks about the depth of the tree not the noof nodes
    
    if(rank[u] == rank[v]){
        parent[u] = v;
        rank[v]++;
        //v is main head
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[u] = v;
    }
}
int find_components(vector<int>& parent,int n){
    if(n == 0 || n == 1) return n;
    // set<int> uniq_parents;
    set<int> uniq_parents(parent.begin(),parent.end());
    return uniq_parents.size();
    // for(int i=0;i<n;i++){
    //     uniq_parents.insert(find_parent(i,parent));
    // }
    // return uniq_parents.size();
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        vector<vector<int>> ans;
        setparent(parent,n);
        for(int i=0;i<n;i++){
            auto x = edges[i];
            int u = x[0];
            int v = x[1];
            if(find_parent(u-1,parent) != find_parent(v-1,parent)){
                makeunion(u-1,v-1,parent,rank);
            }
            else{
                ans.push_back({u,v});
            }
        }
        return ans[ans.size()-1];
    }
};