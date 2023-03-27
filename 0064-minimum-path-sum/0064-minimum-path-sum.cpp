class Solution {
private:
    int dfs(vector<vector<int>> &arr, int i, int j,int n, int m, int &sum, int temp,vector<vector<int>>&dp){
        if(i>=n or j>=m) return INT_MAX;
         temp+=arr[i][j];
        
        
        // cout<<" DEBUG -> "<<arr[i][j]<<" ";
        if(i==n-1 and j == m-1) {
           // cout<<endl;
            return arr[i][j];
        }
        
       
        if(dp[i][j] != -1) return dp[i][j]; 
        
        return dp[i][j] = arr[i][j] + min(dfs(arr, i+1, j, n, m , sum, temp,dp),dfs(arr, i, j+1, n, m, sum, temp,dp));
        
        
          
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int ans = INT_MAX;
        
        
        
        int temp =  0, n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        
        int fuck = dfs(grid,0,0,n,m,ans,temp,dp);
        
        
        return fuck;
    }
};