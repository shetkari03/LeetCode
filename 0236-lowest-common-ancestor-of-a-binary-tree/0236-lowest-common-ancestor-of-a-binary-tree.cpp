/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode* root,TreeNode*p,TreeNode*q,TreeNode*&ans,int &ct){
    if(!root || ans!=NULL)return;
    bool f=(ct==0);
    if(root==q || root==p)ct++;
    if(ct==2)return;
    dfs(root->left,p,q,ans,ct);
    dfs(root->right,p,q,ans,ct);
   //if(ct==2 && f)cout<<root->val<<endl;
    if(ct==2 && f && !ans) ans=root;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)return root;
        TreeNode*ans=NULL;
        int ct=0;
        dfs(root,p,q,ans,ct);
        return ans; 
    }
};