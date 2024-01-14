class Solution {

private:
    int dfs(int ind, int curr_amount, int target, vector<int> &arr, vector<vector<int>>&dp){
        
        if(ind>=arr.size()) return 1e9;
        
        if(arr[ind]>2e4) return 1e9;
        
        if(curr_amount>target) return 1e9;
        
        if(curr_amount == target) return 0;
        
        if(dp[ind][curr_amount] != -1) return dp[ind][curr_amount];
        
        int take = 1LL + dfs(ind, curr_amount+arr[ind], target, arr, dp);
        
        int not_take = dfs(ind+1, curr_amount, target, arr, dp);
    
        
        return dp[ind][curr_amount] =  min(take, not_take);
        
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        
        int curr_amount = 0, n = coins.size();
        
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        
        int ans = dfs(0,curr_amount, amount ,coins, dp);
        
        if(ans == 1e9) ans = -1;
        
        return ans;
    }
};