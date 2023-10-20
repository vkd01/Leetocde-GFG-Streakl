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
    void preorder(TreeNode *root, vector<int>&arr){
        if(root==NULL) return;
        
        
     
        preorder(root->left, arr);
           arr.push_back(root->val);
        preorder(root->right, arr);
        
        
    }
    
    void make(TreeNode *root, vector<int> &arr, int &ind){
        if(root==NULL) return;
        
        
        make(root->left, arr,ind);
        root->val = arr[ind++];
        make(root->right, arr, ind);
        
        
    }
public:
    void recoverTree(TreeNode* root) {
        
        vector<int> arr;
        
        
        preorder(root, arr);
        
        sort(arr.begin(), arr.end());
        int ind = 0;
        
        make(root, arr,ind);
        
       
        
        // for(auto&i:arr) cout<<i<<" ";
        // cout<<endl;
        
        
        
    }
};