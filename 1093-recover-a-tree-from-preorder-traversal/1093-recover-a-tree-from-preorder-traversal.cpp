/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(int &i,int d,string traversal,TreeNode* &root){
    if(i>=traversal.size())return;
    int j=i,ct=0;
    while(j<traversal.size() && traversal[j]=='-' ){
        j++;
        ct++;
    }
    if(ct==d){
        int n=0;
        while(j<traversal.size() && traversal[j]!='-'){
            n=n*10+traversal[j]-'0';
            j++;
        }
        root=new TreeNode(n);
        i=j;
        dfs(i,d+1,traversal,root->left);
        dfs(i,d+1,traversal,root->right);
    }
    
}
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root;
        int i=0;
        dfs(i,0,traversal,root);
        return root;
    }
};