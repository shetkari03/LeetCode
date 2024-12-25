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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int m=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* r=q.front();q.pop();
                m=max(m,r->val);
                if(r->left)q.push(r->left);
                if(r->right)q.push(r->right);
            }
            ans.push_back(m);
        }
        return ans;
    }
};