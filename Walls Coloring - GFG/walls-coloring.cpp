//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{ 
    
public:

    int dfs(vector<vector<int>> &arr, int prev, int ind,vector<vector<int>>&dp){
        if(ind<0) return 0;
        
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int ans = INT_MAX;
                    
        if(prev == 0){
           ans = min(ans, dfs(arr,1,ind-1,dp) + arr[ind][1]);
           ans = min(ans, dfs(arr,2, ind-1,dp) + arr[ind][2]);
        }
        if(prev == 1){
           ans = min(ans, dfs(arr,0,ind-1,dp) + arr[ind][0]);
           ans = min(ans, dfs(arr,2, ind-1,dp) + arr[ind][2]);
        }
        if(prev == 2){
           ans = min(ans, dfs(arr,1,ind-1,dp) + arr[ind][1]);
           ans = min(ans, dfs(arr,0, ind-1,dp) + arr[ind][0]);
        }
        
        return dp[ind][prev] = ans;
        
    }
public:
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        int ans = INT_MAX;
        
         vector<vector<int>>dp(n, vector<int>(3,-1));
        
        ans = min(ans, dfs(colors, 0, n-2,dp) + colors[n-1][0]);
        ans = min(ans, dfs(colors, 1, n-2,dp) + colors[n-1][1]);
        ans = min(ans, dfs(colors, 2, n-2,dp) + colors[n-1][2]);
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends