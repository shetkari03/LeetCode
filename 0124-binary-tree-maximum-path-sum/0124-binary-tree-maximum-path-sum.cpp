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
int dfs(TreeNode* root,int &ans){
    if(!root)return 0;
    int left=0;
    if(root->left)left= dfs(root->left,ans);
    int right=0;
    if(root->right)right=dfs(root->right,ans);
    int d=root->val;
    if(left>0)d+=left;
    if(right>0)d+=right;
    ans=ans>d?ans:d;
    if(min(left,right)>0)d-=min(left,right);
    return d;
}
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int d=dfs(root,ans);
        return ans;
    }
};