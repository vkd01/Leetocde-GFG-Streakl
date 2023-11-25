class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& arr) {
        vector<int>ans;
        
        
        int n = arr.size();
        
        vector<int> prefix(n), suffix(n);
        
        prefix[0] = arr[0];
        
        for(int i = 1;i<n;i++) prefix[i] = prefix[i-1] + arr[i];
        
        suffix[n-1] = arr[n-1];
        
        for(int i = n-2;i>=0;i--) suffix[i] = suffix[i+1] + arr[i];
        
        
        for(int i = 0;i<n;i++){
            int left = 0, right = 0;
            
            if(i>0) left = arr[i]*i - prefix[i-1];
            
            if(i<n-1) right = arr[i]*(n-i-1) - suffix[i+1];
            
           // cout<<i<<" "<<left<<" "<<right<<endl;
            
            int val = abs(left) + abs(right);
            
            ans.push_back(val);
        }
        
        
        
        return ans;
    }
};