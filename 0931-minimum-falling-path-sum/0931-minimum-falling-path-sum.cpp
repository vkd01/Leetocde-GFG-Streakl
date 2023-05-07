class Solution {
    
private:
    
    int dfs(int i, int j,vector<vector<int>>&matrix, vector<vector<int>> &dp){
        
        if(j<0 or j>matrix[0].size()-1) return 1e9;
        if(i==0) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = matrix[i][j] + dfs(i-1,j,matrix,dp);
        int left = matrix[i][j] + dfs(i-1,j-1,matrix,dp);
        int right = matrix[i][j] + dfs(i-1,j+1,matrix,dp);
        
        
        return dp[i][j] = min({up,left,right});
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = 1e9, n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i = 0;i<m;i++){
            ans = min(ans, dfs(n-1,i,matrix,dp));
        }
        
        
        return ans;
    }
};