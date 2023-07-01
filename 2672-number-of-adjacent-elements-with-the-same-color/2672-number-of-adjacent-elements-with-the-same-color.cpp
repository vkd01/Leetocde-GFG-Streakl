class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> arr;
        
        arr.resize(n+2,0);
        
        vector<int> ans(queries.size());
        
        int adj = 0, pos = 0;
        
        for(auto&i:queries){
            int ind = i[0];
            int color = i[1];
            
            if(arr[ind]==0){
                if(ind>0 and arr[ind-1]==color) adj++;
                
                if(ind<n-1 and arr[ind+1]==color) adj++;
            }
            
            else{
                if(ind>0 and arr[ind]==arr[ind-1]) adj--;
                if(ind<n-1 and arr[ind]==arr[ind+1]) adj--;
                
                if(ind>0 and arr[ind-1]==color) adj++;
                
                if(ind<n-1 and arr[ind+1]==color) adj++;
            }
            
            arr[ind] = color;
            ans[pos] = adj;
            pos++;
            
        }
        
      
        
        
        
        
        return ans;
    }
};