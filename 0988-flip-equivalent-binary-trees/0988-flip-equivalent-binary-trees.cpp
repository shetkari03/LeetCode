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
bool sol(TreeNode* root1,TreeNode* root2){
    if(root1==NULL){
        bool f=true;
        if(root2==NULL)f=true;
        else f= false;
        cout<<f<<endl;
        return f;
    }
    if(root2==NULL){
        bool f=true;
        if(root1==NULL)f=true;
        else f= false;
        cout<<f<<endl;
        return f;
    }
    cout<<root1->val<<" "<<root2->val<<endl;
    if(root1->val!=root2->val){
        //ans=false;
        return false;
    }
    bool t=true,m=true;
    t&=sol(root1->left,root2->right);
    t&=sol(root1->right,root2->left);
    m&=sol(root1->left,root2->left);
    m&=sol(root1->right,root2->right);
    t=t|m;
    return t;
}
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ans=true;
        ans=sol(root1,root2);
        return ans;
    }
};