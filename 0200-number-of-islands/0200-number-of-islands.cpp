class Solution {
private:
    void dfs(int i, int j, int n , int m, vector<vector<char>> &arr, vector<vector<bool>> &vis){
        if(i<0 or j<0 or i>=n or j>=m) return;
        
        if(vis[i][j] or arr[i][j] == '0') return;
        
        
        vis[i][j] = true;
        
        dfs(i+1,j,n,m,arr,vis);
        dfs(i-1,j,n,m,arr,vis);
        dfs(i,j+1,n,m,arr,vis);
        dfs(i,j-1,n,m,arr,vis);
         
        
        
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> vis(n+1, vector<bool>(m+1,false));
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j] == false){
                    dfs(i,j,n,m,grid,vis);
                    ans++;
                }
            }
        }
        
        
        return ans;
    }
};