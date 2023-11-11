using int2 = pair<int,int>;
class Graph {
public:
const int INF = numeric_limits<int>::max();
    
    int n;
    
    vector<vector<pair<int,int>>> adj;
    
public:
    Graph(int sz, vector<vector<int>>& edges) {
        n = sz;
        adj.resize(sz);
       for(auto&i:edges){
           adj[i[0]].push_back({i[2],i[1]});
       }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        
     priority_queue<int2, vector<int2>, greater<int2>> pq;
        vector<int> dist(n, INT_MAX);
        dist[node1]=0;
        pq.emplace(0, node1);
        while (!pq.empty()) {
            auto [d, i] = pq.top();
    //        cout<<"d="<<d<<" i="<<i<<endl;
            pq.pop();
            if (i == node2) {
                
                addEdge({node1, node2, d});
                return d;
            }
            if (d > dist[i]) continue;    
            int d2;
            #pragma unroll
            for (auto [w, j] : adj[i]) {
                d2=d+w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(d2, j);
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */