//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
const int N = 1e5 + 7;
vector<vector<int>> g;
  vector<int> vis,par,temp;

class Solution
{
 
    
  public:
  
  
   long long dfs(int node, int p = -1){
      vis[node] = 1;
      par[node] = p;
      temp.push_back(node);
      for(auto&i:g[node]){
          if(!vis[i]){
              long long z = dfs(i,node);
              if(z!=-1) return z;
          }
          else if(vis[i]==1){
              long long sum = i;
              while(node!=i){
                  sum+=node;
                  node = par[node];
              }
              if(node==i) return sum;
              return -1;
          }
      }
      return -1;
  }
  
  
  
  long long largestSumCycle(int n, vector<int> a)
  {
    // code here
    long long ans = -1;
    g = vector<vector<int>>(n);
    vis = vector<int>(n);
    par = vector<int>(n);
    
    for(int i = 0;i<n;i++){
        if(a[i]!=-1)
        g[i].push_back(a[i]);
    }
    
    
    for(int i = 0;i<n;i++){
        if(!vis[i]) ans = max(ans,dfs(i));
        for(auto&e:temp){
            vis[e] = 2;
        }
        temp.clear();
    }
    
    
    
    return ans;
    
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends