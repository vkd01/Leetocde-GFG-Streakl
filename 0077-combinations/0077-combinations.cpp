class Solution {
private: 
    void subs(int ind,vector<int>&arr,int k,int n,vector<vector<int>>&ans,vector<int> &ds){
        if(ind == n){
            if(ds.size()==k) ans.push_back(ds);
            return;
        }
        
        //NOT PICK  --->
        subs(ind+1,arr,k,n,ans,ds);
        
        //PICK--->
        ds.push_back(arr[ind]);
        subs(ind+1,arr,k,n,ans,ds);
        ds.pop_back();
      
         
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int> arr,ds;
        for(int i=1;i<=n;i++) arr.push_back(i);
        
        subs(0,arr,k,n,ans,ds);
        
        return ans;
    }
};