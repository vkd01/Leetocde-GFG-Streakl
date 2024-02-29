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
    bool isEvenOddTree(TreeNode* root) {
        
        
        queue<TreeNode*> q;
        
        int level = 0;
        
        q.push(root);
       // if(root->val%2!=0) return false;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            int prev;
            
            (level&1) ? prev = 1e9 : prev = -1e9;  
            
            while(sz--){
                TreeNode *f = q.front();
                q.pop();
               // cout<<level<<" "<<f->val<<" "<<endl;
               // cout<<f->val<<" "<<prev<<endl;
                if((level%2 == f->val%2)) return false;
                
                if(level&1 and f->val>=prev) return false;
                else if(level%2==0 and f->val<=prev) return false;
                
                prev = f->val;
                
                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
            }
            
            level++;
            
            
        }
        
        
        
        
        return  true;
    }
};