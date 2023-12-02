class Solution {
private:
    int dfs(int i, int curr,int sum, vector<int>&arr, vector<vector<int>>&dp){
        int n = arr.size();
        if(i>=n) return 0;
        
        if(curr==sum) return 1;
        
        if(dp[i][curr] != -1) return dp[i][curr];
        
        
        int ans = 0;
        
        if(arr[i] + curr<=sum){
           ans = ans + dfs(i, curr+arr[i],sum, arr,dp);
        } 
        
        ans = ans + dfs(i+1, curr,sum, arr,dp);
        
        
        return dp[i][curr] = ans;
        
    }
public:
    int change(int amount, vector<int>& coins) {
        int ans = 0, n = coins.size();
        
        vector<vector<int>>dp(n+1, vector<int>(amount+100,-1));
        
        ans = dfs(0,0,amount,coins,dp);
        
        
        
        return ans;
    }
};