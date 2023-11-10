class Solution {
private:
    void dfs(int v,map<int,bool>&vis, map<int, vector<int>>&graph, vector<int>&ans){
        if(vis[v]==true) return;
        ans.push_back(v);
        
        vis[v] = true;
        
        for(auto&i:graph[v]){
            dfs(i,vis,graph,ans);
        }
        
        
    }
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        vector<int> ans;
        
        int first = -1;
        
        map<int,int> mp;
        for(auto&i:arr) mp[i[0]]++, mp[i[1]]++;
        
        for(auto&i:mp){
            if(i.second==1) first = i.first;
        }
               
        
        map<int, vector<int>> graph;
        
        map<int, bool> vis;
        
        for(auto&i:arr){
            vis[i[0]] = false;
            vis[i[1]] = false;
        }
        
        for(auto&i:arr){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        
        dfs(first,vis,graph, ans);
        
        
        return ans;
    }
};