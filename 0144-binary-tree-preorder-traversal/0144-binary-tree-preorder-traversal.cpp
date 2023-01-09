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
    vector<int> preorderTraversal(TreeNode* root) {
        // ITERATIVE APPROACH USING STACK DARA Structure
        
        vector<int>ans;
        if(root==NULL) return ans;
        
        
        stack<TreeNode*> stck;
        
        stck.push(root);
        
        
        while(!stck.empty()) {
        TreeNode* temp = stck.top();
        stck.pop();
        ans.push_back(temp->val);
        
        if(temp->right != NULL) stck.push(temp->right);
        if(temp->left != NULL) stck.push(temp->left);
        }
        
        
        return ans;
    }
};