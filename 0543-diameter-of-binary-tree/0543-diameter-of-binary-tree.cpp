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
private:
    int dfs(TreeNode *root, int &res){
        if(root==NULL) return 0;
        
        int left = dfs(root->left, res);
        int right = dfs(root->right,res);
        
        int temp = max(left,right) + 1;
        int self = left + right;
        
        res = max(res, self);
        
        
        return temp;
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
          dfs(root,ans);
        
        return ans;
    }
};








