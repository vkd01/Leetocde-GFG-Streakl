//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long
#define ll long long
class DisjointSet {

   
public:
 vector<ll> rank, parent;
    DisjointSet(ll n) {
        rank.resize(n + 1, 0LL);
        parent.resize(n + 1);
        for (ll i = 0; i < n; i++) parent[i] = i;
    }

    ll find_ultimate_parent(ll node) {
        if (node == parent[node]) return node;
        return parent[node] = find_ultimate_parent(parent[node]);
    }

    void Union(ll u, ll v) {
        u = find_ultimate_parent(u);
        v = find_ultimate_parent(v);

        if (u == v) return;
        parent[v] = u;

    }

    void UnionByRank(ll u, ll v) {
        ll ulp_u = find_ultimate_parent(u);
        ll ulp_v = find_ultimate_parent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) parent[ulp_v] = ulp_u;
        else if (rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        DisjointSet ds(V);
        
        for(ll i= 0;i<V;i++){
            for(ll j = 0;j<V;j++){
                if(adj[i][j]==1){
                    ds.UnionByRank(i,j);
                    
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<V;i++){
            if( ds.parent[i]==i) ans++;
        }
        return ans;
    }
};






















//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends