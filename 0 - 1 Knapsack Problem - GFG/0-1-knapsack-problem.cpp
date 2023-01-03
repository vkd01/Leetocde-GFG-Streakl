//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    // RECURSION + MEMOIZATION  (DP)
    private:
    int f(int ind, int w,int *wt, int *val,vector<vector<int>> &dp){
        if(ind == 0) {
        e = INT_MIN;
        if(wt[i    if(wt[0]<=w) return val[0];
            return 0;
        }
        if(dp[ind][w]!=-1) return dp[ind][w];
        
        int not_take = 0 + f(ind-1,w,wt,val,dp);
        int taknd]<=w){
            take = val[ind] + f(ind-1,w-wt[ind],wt,val,dp);
        }
        return dp[ind][w] = max(take,not_take);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       
       vector<vector<int>> dp(n,vector<int>(w+1,-1));
       int ans = f(n-1,w,wt,val,dp);
       
       return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends