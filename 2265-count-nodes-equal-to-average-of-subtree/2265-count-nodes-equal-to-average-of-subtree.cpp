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
    pair<int,int> rec(TreeNode *root, int &ans){
        
        if(root==NULL) return {0,0};
        
        pair<int,int> left = rec(root->left, ans);
        pair<int,int> right = rec(root->right, ans);
        
        int sum = left.first + right.first + root->val;
        
        int count = left.second + right.second +1;
        
        if(count>0)
        if(sum/count == root->val) ans++;
        
        return {sum,count};
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        
        
        int ans = 0;
        
        rec(root, ans);
        
        
        
        return ans;
        
    }
};