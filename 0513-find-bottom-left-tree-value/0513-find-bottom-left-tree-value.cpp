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

void bfs(TreeNode *root, vector<vector<int>>&ans){


//step 1 
   queue<TreeNode*> q;

   //step2 : 
   q.push(root);

     //step3 

   while(!q.empty()){

       int sz = q.size();

       vector<int> temp;

// Ek level ke bando ko hum temp mein daal rhe hain

       for(int i = 0;i<sz;i++){
          TreeNode *f = q.front();
          q.pop();
           
           temp.push_back(f->val);

          if(f->left != NULL) q.push(f->left);
          if(f->right != NULL) q.push(f->right);

          

    }

    ans.push_back(temp);


}

}
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        bfs(root, ans);
        
        
        return ans.back()[0];
        
        
    }
};






