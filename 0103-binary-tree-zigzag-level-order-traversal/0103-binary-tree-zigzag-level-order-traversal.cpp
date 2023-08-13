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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        
        if(root==NULL) return {};
        if(root->right == NULL and root->left == NULL)  {
            ans.push_back({root->val});
            return ans;
        }
        
        q.push(root);
        
        int gate = 0;
        
        while(q.size()){
            
            int sz = q.size();
            
            vector<int> temp;
            
            for(int i = 0;i<sz;i++){
                TreeNode *x = q.front();
                q.pop();
                temp.push_back(x->val);
                
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
                
            }
            
            if(gate == 1) reverse(temp.begin(), temp.end());
            
            ans.push_back(temp);
            gate = 1 - gate;
            
        }
        
        
        
        return ans;
    }
};