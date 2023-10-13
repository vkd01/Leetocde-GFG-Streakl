class Solution {
public:
    int minCostClimbingStairs(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> dp(n+2,0);
        
        dp[0] = 0;
        
        for(int i = 0;i<n;i++){
            dp[i+2] = dp[i] + arr[i];
             
            if(dp[i+1] != 0){
                dp[i+1] = min(dp[i+1], dp[i] + arr[i]);
            }
        }
        
        
        return min(dp[n], dp[n+1]);
    }
};