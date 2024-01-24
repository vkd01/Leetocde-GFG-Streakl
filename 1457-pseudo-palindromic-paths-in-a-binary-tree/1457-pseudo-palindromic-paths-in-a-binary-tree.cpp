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
    void dfs(TreeNode *root, map<int,int>&mp, int &ans){
        
        if(root==NULL) return;
        mp[root->val]++;
        
        if(root->left==NULL and root->right==NULL){
            int odd = 0;
            for(auto&i:mp){
                odd+=(i.second&1);
            }
            
           // cout<<odd<<endl;
            
            ans+=(odd<2);
        }
        
        
        
//         for(auto&i:mp) cout<<i.first<<' '<<i.second<<endl;
        
//         cout<<"-------------------"<<endl;
        
        dfs(root->left, mp, ans);
        
        dfs(root->right, mp, ans);
        
        mp[root->val]--;
        if(mp[root->val] == 0) mp.erase(mp[root->val]);
        
        
        
        
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        map<int,int> mp;
        int ans = 0;
        
        dfs(root, mp, ans);
        
        return ans;
    }
};