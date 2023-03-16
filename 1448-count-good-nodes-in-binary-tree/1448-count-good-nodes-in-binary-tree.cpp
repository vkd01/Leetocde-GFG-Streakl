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
    void dfs(TreeNode *root, int &ans, int mx){
        if(root==NULL) return;
        if(root->val >= mx) {
            ans++;
            mx = root->val;
        }
    
        
        dfs(root->left, ans, mx);
        dfs(root->right, ans,mx);
        
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        
        dfs(root,ans, root->val);
        
        
        return ans;
        
    }
};