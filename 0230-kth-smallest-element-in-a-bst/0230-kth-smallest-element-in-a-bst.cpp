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
    void inorder(TreeNode*root,int &ct,int k,int &ans){
        if(!root)return;
        inorder(root->left,ct,k,ans);
        ct++;
        if(ct==k)ans=root->val;
        inorder(root->right,ct,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ct=0,ans=0;
        inorder(root,ct,k,ans);
        return ans;
    }
};