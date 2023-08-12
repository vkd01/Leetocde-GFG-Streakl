class Solution {
private:
    vector<vector<int>> dp;
    
    int dfs(int i, int j,int &r,int &c, int &ans, vector<vector<int>> &grid){
        
        //BASE CASES !!
        if(r==1 and c == 1) {
           if(grid[0][0]==0) ans = 1;
            else ans = 0;
            return 1;
        }
        if(i<0 or j<0 or i>=r or j>=c) return 0;
        if(grid[i][j]==1) return 0; 
        if(i==r-1 and j == c-1) return 1;
        
        
       
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = dfs(i+1,j,r,c,ans,grid);
        int down = dfs(i, j+1,r,c,ans,grid);
        
        ans = down+right;
        
        return dp[i][j] = down+right;   
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        
        dp.resize(r+1,vector<int>(c+1,0));
        
      //  dfs(0,0,r,c,ans,grid);
        
        //SPACE OPTIMIZATION !!
        
        if(r==1 and c==1){
            if(grid[0][0] == 0) return 1;
            else return 0;
        }
        
        dp[0][1] = 1;
        
        for(int i = 1;i<=r;i++){
            for(int j = 1;j<=c;j++){
                if(grid[i-1][j-1] != 1) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
//         for(auto&i:dp) {
//             for(auto&j:i) cout<<j<<" ";
//             cout<<endl;
//         }
        
 
        return dp[r][c];
    }
};















