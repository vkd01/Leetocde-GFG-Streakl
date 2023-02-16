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
    int dfs(TreeNode * root){
        int ans = 0;
        
        if(root==NULL) return 0;
        
        ans = max(ans, 1 + dfs(root->left));
        ans = max(ans, 1 + dfs(root->right));
        
        
        return ans;
        
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        
        ans = dfs(root);
        
        
        return ans;
    }
};