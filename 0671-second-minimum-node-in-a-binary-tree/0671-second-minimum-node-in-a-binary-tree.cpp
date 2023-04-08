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
    
    void dfs1(TreeNode *root, long &mn){
        if(root==NULL) return;
        
    //    mn = min(mn, root->val);
        if(mn>root->val) mn = root->val;
        
        dfs1(root->left, mn);
        dfs1(root->right, mn);   

    }
    
    void dfs2(TreeNode *root, long &smin, long &mn){
        
        if(root==NULL) return;
        
        if(root->val<smin and root->val>mn) {
            smin = root->val;
        }
        
        dfs2(root->left, smin,mn);
        dfs2(root->right, smin,mn);
        
        
    }
    
public:
    int findSecondMinimumValue(TreeNode* root) {
        long mn = LONG_MAX, smin = LONG_MAX;
        
        dfs1(root,mn);
        
     //   cout<<mx<<endl;
        
        dfs2(root,smin,mn);
        
        if(smin == LONG_MAX) smin = -1;
        
        
        return smin;
    }
};