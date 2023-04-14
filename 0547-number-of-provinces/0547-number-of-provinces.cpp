class Solution {
private:
    void dfs(int vertex,vector<int> *graph, vector<bool> &vis){
          vis[vertex] = true;
        
        for(auto&child:graph[ vertex]){
            if(!vis[child]) dfs(child,graph, vis);
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        
        int n = isConnected.size();
        
        vector<int> graph[n+1];
        
        vector<bool> vis(n+1, false);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }                                         
        }
        
        
        for(int i = 1;i<n+1;i++){
            if(!vis[i]) {
                dfs(i,graph,vis);
                ans++;
            }
        }
     
        
//         for(int i =0 ;i<n+1;i++){
//             cout<<"Parent -> "<<i<<" ->";
//             for(auto&ii:graph[i]) cout<<ii<<" ";
//             cout<<endl;
//         }
        
        
        
        return ans;
    }
};