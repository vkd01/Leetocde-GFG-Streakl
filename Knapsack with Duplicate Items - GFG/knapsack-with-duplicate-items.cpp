//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:


    int rec(int ind,int w, vector<pair<int,int>>&arr, vector<vector<int>>&dp){
        
        if(ind>=arr.size()) {
            return 0;
        }
        
        if(w <= 0){
            return 0;
        } 
        
       if(dp[ind][w] != -1) return dp[ind][w];
        
        int ans = 0, take = 0, not_take = 0;
        
        if(arr[ind].second<=w){
             take = arr[ind].first + rec(ind, w-arr[ind].second,arr,dp);
        }
        
        not_take = rec(ind+1, w, arr,dp);
        
        
        
       //  cout<<ind<<" "<<take<<" "<<" "<<not_take<<endl;
        
        return dp[ind][w] = max(take, not_take);
        
        
    }


public:
    int knapSack(int N, int w, int val[], int wt[])
    {
        // code here
        vector<pair<int,int>> arr;
        
        for(int i = 0;i<N;i++){
            arr.push_back({val[i], wt[i]});
        }
        
        int ans = 0;
        
        vector<vector<int>>dp(N+100, vector<int>(w+100,-1));
        
        ans = rec(0, w, arr,dp);
        
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends