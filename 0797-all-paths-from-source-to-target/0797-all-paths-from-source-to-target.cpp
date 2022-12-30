class Solution {
    
private:
    void dfs(int vertex, vector<vector<int>> &graph,vector<int>&paths,vector<bool>&visited,vector<vector<int>>&ans,int &n){
        if(visited[vertex]==true) return;
        visited[vertex] = true;
        paths.push_back(vertex);
        if(vertex==n-1) ans.push_back(paths);
        for(auto&child:graph[vertex]) dfs(child,graph,paths,visited,ans,n);
        //Backtrack !!
        paths.pop_back();
        visited[vertex] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        int n = graph.size();
        
        vector<bool> visited(n,false);
        vector<int>paths;
        
        dfs(0,graph,paths,visited,ans,n);
        
        
        return ans;
    }
};