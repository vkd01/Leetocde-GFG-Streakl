class Solution {
private:
    int f(vector<int> &coins, int amount,vector<int> &dp){
         
        if(amount == 0) return 0;
        int ans = INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        for(auto&i:coins){
            if(amount-i >= 0) ans = min((long long)ans, 1LL + f(coins,amount-i,dp));
        }
        return dp[amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0; 
        vector<int> dp(amount+1,-1);
        ans = f(coins,amount,dp);
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};