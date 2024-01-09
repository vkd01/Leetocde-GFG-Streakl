class Solution {

int rec(int step, int n, vector<int>&dp){
    
    //base case
    if(step>n) return 0;
    if(step==n) return 1;
    
    if(dp[step] != -1) return dp[step];
    
    
    int one_step = rec(step+1, n, dp);
    int two_step = rec(step+2, n,dp);
    
    return dp[step] = one_step + two_step;
    
}
    
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        
        int ans = rec(0,n, dp);
        
        
        return ans;
    }
};