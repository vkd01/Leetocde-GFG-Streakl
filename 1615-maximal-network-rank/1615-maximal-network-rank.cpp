class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        
        
        vector<int> degree(n+1, 0);
        
         set<int> st;
         set<pair<int, int>> edges;
        
        for(auto&i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
            
            st.insert(i[0]);
            st.insert(i[1]);
            
            edges.insert({i[0], i[1]});
            edges.insert({i[1], i[0]});
        }
        
       
        
        vector<int> nodes;
        for(auto&i:st) nodes.push_back(i);
        
        
        for(int i = 0;i<nodes.size();i++){
            for(int j = 0;j<nodes.size();j++){
                if(i==j) continue;
                
                int x = nodes[i], y = nodes[j];
                
                int connections = degree[x] + degree[y];
                
                if(edges.find({x,y}) != edges.end()){
                    connections--;
                }
                 ans = max(ans, connections);
                
            }
           
        }
       
        
        
        
        
        return ans;
    }
};