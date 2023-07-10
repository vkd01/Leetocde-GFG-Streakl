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

    void bfs(TreeNode *root, int &ans){
        queue<TreeNode*> q;
        
        q.push(root);
        
        
        while(!q.empty()){
            ans++;
            int sz = q.size();
            
            while(sz--){
                TreeNode *fr = q.front();
                q.pop();
                
                if(fr->left == NULL and fr->right == NULL) return;
                
                if(fr->left != NULL) q.push(fr->left);
                if(fr->right != NULL) q.push(fr->right);
                
                
            }
        }
        
        
    }
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        
        if(root==NULL) return 0;
        
        
        
        bfs(root, ans);
        
        
        return ans;
    }
};