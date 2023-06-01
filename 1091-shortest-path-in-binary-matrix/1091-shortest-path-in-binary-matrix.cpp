class Solution {
public:
void dfs(int u,int v,vector<vector<int>>& g,vector<vector<int>>& dist)
    {
        int n=g.size(),m=g[0].size();
        
        int d0=dist[u][v];
        
       for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0)
                    continue;   
            
                int i=u+x,j=v+y;
                
                
                
            if(i>=0 && i<n && j>=0 && j<m)
            {  if(g[i][j]==1)continue;
             
                int d1=dist[i][j];
            
            if(d0-1>d1)//checking if it is minimum for u,v
            {
                dist[u][v]=d1+1;
                dfs(u,v,g,dist);
            }
                else if(d0<d1-1){//checking if it is minimum for i,j
                    dist[i][j]=d0+1;
                    dfs(i,j,g,dist);
                }
             
            }
        
        }
           
       }
       
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        
        int i,j,n=g.size(),m=g[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));//dist from ,i,j, to 0,0
        
        dist[0][0]=1;
        
            if(g[0][0]==1 || g[n-1][m-1]==1)
            {
                return -1;
            }
        
        dfs(0,0,g,dist);
        
        return dist[n-1][m-1]==INT_MAX ? -1:dist[n-1][m-1];
    }
};