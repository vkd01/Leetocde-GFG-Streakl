class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int ans = 0,n = arr.size();
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        vector<int> fuck;
        
        fuck.push_back(1);
        for(auto&i:arr) fuck.push_back(i);
        fuck.push_back(1);
        
        for(int i = 1;i<=n;i++){
            for(int start = 1;start<=n-i+1;start++){
                
                int end = start + i - 1;
                int ans = 0;
                
                for(int k = start;k<=end;k++){
                    ans = max(ans, dp[start][k-1] + dp[k+1][end] +
                              fuck[start -1]*fuck[k]*fuck[end+1]);
                }
                
                dp[start][end] = ans;
                
            }
        }
        
        
        return dp[1][n];
    }
};