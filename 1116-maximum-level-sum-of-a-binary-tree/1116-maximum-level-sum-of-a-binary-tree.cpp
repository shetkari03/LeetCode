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
    int maxLevelSum(TreeNode* root) {
        long long ans=INT_MIN;
        int level=1,k=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeNode* t;
            long long sum=0;
            for(int i=0;i<n;i++){
                t=q.front();q.pop();
                sum+=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(sum>ans){
                ans=sum;
                k=level;
            }
            level++;
        }
        return k;
    }
};