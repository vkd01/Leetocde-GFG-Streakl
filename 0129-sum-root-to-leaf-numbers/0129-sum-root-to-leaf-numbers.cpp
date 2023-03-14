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
    void dfs(TreeNode *root, int &ans, int temp = 0){
        
         temp*=10;
        temp+=root->val;
        
        if(root->left==NULL and root->right == NULL){
            ans+=temp;
            cout<<temp<<endl;
            return;
        }
        
       
        
        
        
        if(root->left != NULL)  dfs(root->left, ans, temp);
        if(root->right != NULL) dfs(root->right,ans, temp);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        
        dfs(root, ans,0);
        
        
        return ans;
    }
};