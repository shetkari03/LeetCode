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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ct=0;
        while(!q.empty()){
            int n=q.size();
            queue<TreeNode*>temp;
            stack<int>st;
            for(int i=0;i<n;i++){
                TreeNode* p=q.front();q.pop();
                temp.push(p);
                st.push(p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
               
            }
             if(ct%2){
                    for(int i=0;i<n;i++){
                        TreeNode*p=temp.front();temp.pop();
                        p->val=st.top();st.pop();
                    }
                }
            ct++;
        }
        return root;
    }
};