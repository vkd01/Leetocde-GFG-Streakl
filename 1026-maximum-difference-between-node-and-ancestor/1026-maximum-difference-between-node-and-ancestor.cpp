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
    
    int find_ans(TreeNode *root, int mn, int mx){
        if(root == NULL) return abs(mn - mx);
        
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        
        
        int left = find_ans(root->left, mn, mx);
        int right = find_ans(root->right, mn, mx);
        
        return max(left, right);
    }
    
    
public:
    int maxAncestorDiff(TreeNode* root) {
        
        
        int mx = -1e9, mn = 1e9;
        
        int ans = find_ans(root, mn, mx);
        
        
        return ans;
    }
};