class Solution {
    
 class DSU {
 vector<int> rank, parent;
 public:
 void DisjointSet(int n) {
 rank.resize(n + 1, 0LL);
 parent.resize(n + 1);
 for (int i = 0; i < n; i++) parent[i] = i;
 }
 int find_ultimate_parent(int node) {
 if (node == parent[node]) return node;
 return parent[node] = find_ultimate_parent(parent[node]);
 }
 void Union(int u, int v) {
 u = find_ultimate_parent(u);
 v = find_ultimate_parent(v);
 if (u == v) return;
 parent[v] = u;
 }
 void UnionByRank(int u, int v) {
 int ulp_u = find_ultimate_parent(u);
 int ulp_v = find_ultimate_parent(v);
 if (ulp_u == ulp_v) return;
 if (rank[ulp_u] < rank[ulp_v]) parent[ulp_v] = ulp_u;
 else if (rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
 else {
 parent[ulp_v] = ulp_u;
 rank[ulp_u]++;
 }}};
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu;
        
        int n = isConnected.size();
        
        dsu.DisjointSet(n);
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    dsu.Union(i,j);
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            if(dsu.find_ultimate_parent(i) == i) ans++;
        }
        
        
        return ans;
    }
};






















