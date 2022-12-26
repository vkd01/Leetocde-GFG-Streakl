class Solution {
    int f(int n, int &ans, vector<int>&dp){
        if(n==0) return 1;
        else if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        ans+= f(n-1,ans,dp);
        dp[n] = ans;
        ans+= f(n-2,ans,dp);
        dp[n] = ans;
        
        return 0;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        int ans = 0;
        
        int fuck = f(n,ans,dp);
        
        return ans;
        
    }
};