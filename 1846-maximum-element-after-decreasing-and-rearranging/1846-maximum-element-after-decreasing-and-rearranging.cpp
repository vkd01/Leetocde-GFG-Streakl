class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int ans = 0;
        
        
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        
        
        
        for(int i = 0;i<arr.size()-1;i++){
            arr[i+1] = min(arr[i]+1, arr[i+1]);
        }
        
        ans = *max_element(arr.begin(), arr.end());
        
        
        
        return ans;
    }
};