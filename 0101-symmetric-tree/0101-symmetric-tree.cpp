 bool sym(TreeNode* l, TreeNode* r){
        if(l==NULL&& r==NULL)
            return true;
        if(l==NULL|| r==NULL)
            return false;
        return (l->val==r->val && sym(l->left,r->right) && sym(l->right,r->left));
    }
class Solution {
public:
   
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return sym(root->left, root->right);
    }
};