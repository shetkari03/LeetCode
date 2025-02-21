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
 #include<bits/stdc++.h>
class FindElements {
public:
map<int,int>hash;
    FindElements(TreeNode* root) {
        int n=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        hash[0]=1;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                TreeNode* r=q.front().first;
                int k=q.front().second;
                q.pop();
                if(r->left){
                    q.push({r->left,k*2+1});
                    hash[2*k+1]=1;
                }
                if(r->right){
                    q.push({r->right,k*2+2});
                    hash[2*k+2]=1;
                }
            }
        }
    }
    
    bool find(int target) {
        return hash[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */