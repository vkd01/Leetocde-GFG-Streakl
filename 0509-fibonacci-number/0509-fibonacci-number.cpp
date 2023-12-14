class Solution {
private:
    int dfs(int n, vector<int>&dp){
        
        if(n<2) return n;
        
        if(dp[n] != -1) return dp[n];
        
        int left = dfs(n-1,dp);
        int right = dfs(n-2,dp);
        
        
        return dp[n] =  left+right;
        
        
    }
public:
    int fib(int n) {
        
        vector<int> dp(n+1, -1);
        
        int ans = dfs(n, dp);
        
        
        return ans;
    }
};