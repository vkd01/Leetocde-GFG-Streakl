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

TreeNode *first, *middle, *last, *prev;
    
private:
    void dfs(TreeNode *root){
        
        if(root==NULL) return;
        
       if(first)
        cout<<first->val<<" "<<endl;
        if(middle) cout<<middle->val<<endl;
        if(last)cout<<last->val<<endl;
        
        dfs(root->left);
        
        
        if(prev != NULL and prev->val>root->val){
            
         //   cout<<"Debug "<<endl;
            
            if(first == NULL){
             //   cout<<"Debug 2"<<endl;
                first = prev;
                middle = root;
            }
            else {
             //   cout<<"Debug 3"<<endl;
                last = root;
            }
        }
        
    
        prev = root;
        dfs(root->right);
        
    }
public:
    void recoverTree(TreeNode* root) {
        
         prev = new TreeNode(INT_MIN);
        
         first = NULL,middle = NULL, last = NULL;
        
        
        dfs(root);
        
       // cout<<first->val<<endl;
        
        
        if(first != NULL and last != NULL) swap(first->val, last->val);
        else if(first != NULL and middle!=NULL) swap(first->val, middle->val);
         
        
        
    }
};