//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   int minimumCost(vector<vector<int>>& f, int n, int k) {

       

       vector<int>d;

       for(int i=0;i<=n;i++)

       {

           d.push_back(INT_MAX);

          

       }

       unordered_map<int,list<pair<int,int>>>adj;

       for(int i=0;i<f.size();i++)

       {

           int u=f[i][0];

           int v=f[i][1];

           int w=f[i][2];

           

          adj[u].push_back({v,w}); 

    

       }

       

 

     set<pair<int,int>>s;

     d[k]=0;

      s.insert({0,k});

      while(s.size())

      {

        auto g=*s.begin(); 

        int dis=g.first;

        int  node= g.second;

        s.erase(s.begin());

        

        for(auto it: adj[node])

        {

            if(dis+it.second<d[it.first])

            {

                auto rec=s.find({d[it.first],it.first});

                if(rec!=s.end())

                {

                    s.erase(rec);

                }

                d[it.first]=dis+it.second;

                s.insert({d[it.first],it.first});

            }

        }

        

      }

     int ans=0;;  

    for(int i=1;i<=n;i++)

    {

      if(d[i]==INT_MAX)

      return -1;

      else

      {

          ans=max(ans,d[i]);

      }

    }

     return ans;  

       

          }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends