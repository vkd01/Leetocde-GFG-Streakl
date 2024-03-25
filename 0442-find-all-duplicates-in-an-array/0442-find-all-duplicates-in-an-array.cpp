class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        
        vector<int> ans;
        
        int n = arr.size();
        
        for(int i = 0; i<n;i++){
            int ind = abs(arr[i]) - 1;
            
            if(arr[ind]<0) ans.push_back(ind+1);
            arr[ind] = -arr[ind];
        }
        
        
        return ans;
        
    }
};