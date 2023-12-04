class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int ans = -1e9+1, n = arr.size(), temp = 0;
        
        for(int i = 0;i<n;i++){
            temp+=arr[i];
            ans = max(ans, temp);
            temp = max(temp,arr[i]);
            
            ans = max(ans, temp);
        }
        
        ans = max(ans, temp);
        
        return ans;
    }
};