//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

#define ll long long 


ll f(int i, int j,int m, int n){
    if(i==m and j==n) return 1;
    else if(i>m or j>n) return 0;
    
    
    ll take = f(i+1,j,m,n);
    ll not_take = f(i,j+1,m,n);
    
    
    return take+not_take;
    
}



long long  numberOfPaths(int m, int n)
{
    // Code Here
    ll ans = f(1,1,m,n);
    
    
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