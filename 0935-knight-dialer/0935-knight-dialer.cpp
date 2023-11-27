const int MOD = 1e9 + 7;

class Solution {
private:
    int dfs(int curr, int steps, vector<vector<int>>&graph, vector<vector<int>>&dp){
        
        if(steps==0) return 1;
        
        if(dp[curr][steps] != -1) return dp[curr][steps];
        
        int ans = 0;
        
        for(auto&i:graph[curr]){
            int x = dfs(i, steps-1, graph, dp);
            
            ans = (ans + x)%MOD;
        }
        
        return dp[curr][steps] = ans;
        
    }
public:
    int knightDialer(int n) {
        
        
        vector<vector<int>> graph(10);
        
        graph[0] = {4,6};
        graph[1] = {6,8};
        graph[2] = {7,9};
        graph[3] = {4,8};
        graph[4] = {0,3,9};
        graph[5] = {};
        graph[6] = {0,1,7};
        graph[7] = {2,6};
        graph[8] = {1,3};
        graph[9] = {2,4};
        
        
        int ans = 0;
        
        vector<vector<int>>dp(10, vector<int>(n+10,-1));
        
        for(int i = 0;i<10;i++){
            
            int x = dfs(i,n-1,graph, dp);
            
            ans = (ans+x)%MOD;
        }
        
        
        return ans;
        
    }
};