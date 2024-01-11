class Solution {
    
private:
    
    int dfs(int ind, int prev, vector<int>&arr, vector<vector<int>>&dp){
        
        if(ind == arr.size()) return 0;
        
        if(prev != -1 and dp[ind][prev] != -1) return dp[ind][prev];
        
        int take = 0, not_take = 0;
        
        not_take = dfs(ind+1, prev, arr, dp);
        
        if(prev == -1 or arr[ind]>arr[prev]){
            take = 1 + dfs(ind+1, ind, arr,dp);
        }
        
        if(prev == -1) return max(take, not_take);
        
        return dp[ind][prev] =  max(take, not_take);
        
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, prev = -1, n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2600, -1));
        
        ans = dfs(0,prev, nums, dp);
        
        return ans;
    }
};