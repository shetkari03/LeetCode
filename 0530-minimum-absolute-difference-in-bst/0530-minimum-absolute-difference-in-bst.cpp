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
void inorder(TreeNode* root,vector<int>&ans){
    if(!root)return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int a=INT_MAX,prev=1000000*-1;
        for(auto it:ans){
            a=min(a,it-prev);
            prev=it;
        }
        return a;
    }
};