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
    void preorder(TreeNode *root, vector<int> &ans){
        
        if(root==NULL) return;
        
        
         ans.push_back(root->val);
        
        preorder(root->left, ans);
        
        preorder(root->right, ans);
        
        
        
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        
        vector<int> arr;
        
        preorder(root, arr);
        
        int mx = 0;
        
        map<int,int> mp;
        
        for(auto&i:arr) mp[i]++;
        
        
        for(auto&i:mp){
            if(i.second>mx){
                mx = i.second;
            }
        }
        
        for(auto&i:mp){
            if(i.second == mx) ans.push_back(i.first);
        }
        
        
        
        
        return ans;
    }
};