
const int MOD = 1e9 + 7;

class Solution {
private:
    int dfs(int max, int n, int m, int i, int j, vector<vector<vector<int>>>&dp){
        if(i>=n or j>=m or i<0 or j<0) return 1;
        
        if(dp[i][j][max] != -1) return dp[i][j][max]; 
        
        int up = 0, down = 0, left = 0, right = 0;
        
        if(max>0) up = dfs(max - 1, n, m, i, j+1, dp);
        if(max>0) down = dfs(max - 1, n, m, i, j-1, dp);
        if(max>0) left = dfs(max - 1, n, m, i-1, j, dp);
        if(max>0) right = dfs(max - 1, n, m, i+1, j, dp);
        
        return dp[i][j][max] = ((up + down)%MOD + (left + right)%MOD)%MOD;
    }
public:
    int findPaths(int m, int n, int maxMove, int i, int j) {
        int ans = 0;
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1,-1)));
        
        ans = dfs(maxMove, m, n, i, j, dp);
        
        return ans;
    }
};