class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int ans = 0, n = arr.size();
        vector<int> prefix(n,0), suffix(n,0);
        
        
        int temp = 0;
        
        for(int i = 0;i<n;i++){
            if(arr[i] == 1) temp++;
            else temp = 0;
            
            prefix[i] = temp;
        }
        
        temp = 0;
        
        
        for(int i = n-1;i>=0;i--){
            if(arr[i]==1) temp++;
            else temp= 0;
            suffix[i] = temp;
        }
        
        for(int i = 0;i<n;i++) {
            ans = max(ans, prefix[i]-1);
            ans = max(ans, suffix[i]-1);
        }

        
        for(int i = 0;i<n;i++){
            if(arr[i]==0){
                if(i == 0) temp = suffix[i+1];
                else if(i==n-1) temp = prefix[i-1];
                else temp = prefix[i-1] + suffix[i+1];
                ans = max(ans, temp);
            }
        }
        
        
        
        
        return ans;
    }
};