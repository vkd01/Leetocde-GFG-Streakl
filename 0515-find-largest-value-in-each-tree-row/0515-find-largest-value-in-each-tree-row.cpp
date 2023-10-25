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
    void bfs(TreeNode *root, vector<int>&ans){
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        
        long long mx = -3e9;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            mx = -3e9;
            
            for(int i = 0;i<sz;i++){
                TreeNode *temp = q.front();
                q.pop();
                mx = max(mx, (long long)temp->val);
                
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                
            }
            
            
            
            ans.push_back((int)mx);
            
            
            
        }
        
        
        
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        if(root==NULL) return {};
        
        bfs(root, ans);
        
        
        return ans;
    }
};