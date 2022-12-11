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
    void dfs(TreeNode *root, int mx,int mn, int &ans){
        if(root==NULL) return;
        
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        
        ans = max(ans,abs(mx-mn));
        
        dfs(root->left,mx,mn,ans);
        dfs(root->right,mx,mn,ans);
        
        
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int mx = INT_MIN, mn = INT_MAX;
        
        dfs(root,mx,mn,ans);
        
        return ans;
    }
};