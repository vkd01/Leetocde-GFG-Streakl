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
    int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>> arr;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        arr.push_back({root->val});
        
        int red = 100000;
        
        while(!q.empty()){
            
            int sz = q.size();
            vector<int> temp;
            
           // cout<<q.size()<<endl;
            
            for(int i = 0;i<sz;i++){
                
                TreeNode* f = q.front();
                q.pop();
                temp.push_back(f->val);
                
                if(f->left != NULL) q.push(f->left);
                  
                if(f->right != NULL) q.push(f->right);
                  
            }
            
            arr.push_back(temp);
            
            
            red--;
            if(red==0) break;
        }
        
        
        return arr.back()[0];
        
        
    }
};