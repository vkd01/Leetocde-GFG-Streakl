class Solution {
 
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        int ans = -1e9;
        
        dp[n] = 0;
        
        for(int i = n-1;i>=0;i--){
            
            int len = 0, mx = -1e5 + 10;
            int best_ans = -1e5 + 10;
        
            for(int j = i;j<min((int)arr.size(), i+k);j++){
                len++;
                mx = max(mx, arr[j]);
                int sum = len*mx + dp[j+1];
                best_ans = max(best_ans, sum);
            }
        
            dp[i] = best_ans;
        }
        
        return dp[0];
    }
};