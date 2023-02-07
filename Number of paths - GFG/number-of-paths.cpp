//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

#define ll long long 


ll f(int i, int j,int m, int n,vector<vector<ll>> &dp){
    if(i==m and j==n) return 1;
    else if(i>m or j>n) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    ll take = f(i+1,j,m,n,dp);
    ll not_take = f(i,j+1,m,n,dp);
    
    
    return dp[i][j] = take+not_take;
    
}



long long  numberOfPaths(int m, int n)
{
    // Code Here
    
    vector<vector<ll>> dp(m+1, vector<ll>(n+1,-1));
        
    for(int i = 0;i<m+1;i++){
        for(int j = 0;j<n+1;j++) dp[i][j] = -1;
    }
    
    
        
        
    ll ans = f(1,1,m,n,dp);
    
    
    return ans;
    
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends