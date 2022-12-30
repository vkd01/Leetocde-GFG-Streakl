class Solution {
public:
    
    void dfs(int vertex,vector<vector<int>> &graph, vector<int>&paths,vector<vector<int>>&ans,vector<bool> &visited,int &n){
        
         
        if(visited[vertex]) return;
        
        visited[vertex] = true;
        
        paths.push_back(vertex);
         if(vertex==n-1) ans.push_back(paths);
        for(auto&child:graph[vertex]){
            
            if(!visited[child])
            dfs(child,graph,paths,ans,visited,n);
            //Bcktracking !!
        
        }
            paths.pop_back();
            visited[vertex] = false;
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        vector<int>paths;
        int n = graph.size();
        vector<bool> visited(n,false);
        
        
        
        dfs(0,graph,paths,ans,visited,n);
        
        
        
        return ans;
    }
};