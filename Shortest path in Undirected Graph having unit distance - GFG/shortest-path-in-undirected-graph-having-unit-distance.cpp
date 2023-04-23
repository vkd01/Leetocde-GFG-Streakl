//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> ans(N,-1);
        
        
        vector<int> graph[N];
        
        for(auto&i:edges){
            int x = i[0], y = i[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        vector<int> dist(N,1e9);
        dist[src] = 0;
        
        queue<int> q;
        
        q.push(src);
        
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto&i:graph[node]){
                if(dist[node] + 1 < dist[i]){
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
        
        
        for(int i=0;i<N;i++){
            if(dist[i] != 1e9) ans[i] = dist[i];
        }
        
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends