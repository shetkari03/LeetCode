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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long sum=0;
            queue<pair<TreeNode*,int>>p;
            map<int,int>mpp;
            for(int i=0;i<n;i++){
                TreeNode* t=q.front().first;
                sum+=t->val;
                if(t->left){
                    q.push({t->left,i});
                }
                if(t->right){
                    q.push({t->right,i});
                }
                mpp[q.front().second]+=t->val;
                p.push(q.front());
                q.pop();
            }
            for(int i=0;i<n;i++){
                TreeNode*t=p.front().first;
                t->val=sum-mpp[p.front().second];
                p.pop();
            }
        }
        return root;
    }
};