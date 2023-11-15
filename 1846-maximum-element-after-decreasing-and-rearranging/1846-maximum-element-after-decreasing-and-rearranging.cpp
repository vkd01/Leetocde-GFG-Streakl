class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int ans = 0, n = arr.size();
        
        if(n==1) return 1;
        
        
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        
        // for(auto&i:arr) cout<<i<<" ";
        // cout<<endl;
        
        for(int i = 0;i<n-1;i++){
            arr[i+1] = min(arr[i]+1, arr[i+1]);
        }
        
        
        
        for(auto&i:arr) ans = max(ans, i);
        
        return ans;
    }
};