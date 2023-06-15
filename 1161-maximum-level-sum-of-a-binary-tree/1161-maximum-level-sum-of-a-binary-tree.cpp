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
    int  bfs(TreeNode *root){
        
        
        deque<TreeNode*> q;
        
        q.push_front(root);
        
        int sum = -1e9, level = 1, ans;
        
        while(!q.empty()){
            
            TreeNode *x = q.front();
            
            int sz = q.size();
            
            int temp  = 0;
            
            for(int i = 0;i<sz;i++){
                TreeNode *xx = q.back();
                q.pop_back();
                temp+=xx->val;
                
                if(xx->left != NULL) q.push_front(xx->left);
                if(xx->right!= NULL) q.push_front(xx->right);
                
            }
            if(temp>sum){
                sum = temp;
                ans = level;
            }
            
            level++;
            
        }
        
        return ans;
        
    }
public:
    int maxLevelSum(TreeNode* root) {
        
        int ans = bfs(root);
        
        return ans;
        
    }
};