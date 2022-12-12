class Solution {
private:
     int f(int &n,int stairs, int &ans,vector<int> &dp){
        if(stairs==n) return 1;
        if(stairs>n) return 0;
        
        if(dp[stairs]!=-1) return dp[stairs];
        
        ans+=f(n,stairs+1, ans,dp);
        dp[stairs] = ans;
        ans+=f(n,stairs+2, ans,dp);
        dp[stairs] = ans;
         
         return 0;
    }
public:
    int climbStairs(int n) {
        int ans = 0,stairs = 0;
        vector<int> dp(n+1,-1);
        f(n,stairs,ans,dp);
        
        return ans;
    }
};