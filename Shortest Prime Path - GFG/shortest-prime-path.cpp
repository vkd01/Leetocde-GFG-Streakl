//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
bool cmp(int n1, int n2) // check if two numbers differ by a single digit
{
    int diff = 0;
    while(n1!=0 && n2!=0)
    {
        if((n1%10) != (n2%10)) diff++;
        n1/=10;
        n2/=10;
    }
    
    return (diff==1);
}

vector<int> primes; // to store all the prime numbers between 1000 and 9999
vector<bool>sieve(10000,1);
vector<vector<int>> adj(2000+1);

class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        
        
        int n = primes.size();
        if(primes.size()==0) // check if it is the first run
            {
                sieve[0]=sieve[1] = 0;
                for(int i=2; i<=9999; i++)
                {
                    if(sieve[i]) // if i is prime
                    {
                       if(i>1000) primes.push_back(i); // pushing all 4 digit prime numbers in primes
                        for(int j=i*i; j<=9999; j+=i)
                        {
                            sieve[j] = 0; // j is not a prime number
                        }
                    }
                    
                }
                
                
                
            
                n= primes.size();
        
                
                // Creating adjacency list adj
                for(int i=0; i<n; i++)
                {
                    for(int j=i+1; j<n; j++)
                    {
                        if(cmp(primes[i],primes[j])) // check if numbers at i-th and j-th differ by a single digit
                        {
                            adj[i].push_back(j); 
                            adj[j].push_back(i);
                        }
                    }
                }
            
            }
        
        
        
        int idx1 = -1; // to store index of Num1 in primes[]
        int idx2 = -1; // to store index of Num2 in primes[]
        for(int i=0; i<n; i++)
        {
            if(primes[i]==Num1)
            {
                idx1=i;
                
            }
            if(primes[i]==Num2)
            {
                idx2 = i;
                
            }
        }
        
        if((idx1==-1) || (idx2==-1)) return -1; // if Num1 or Num2 not found
        
        
        
        // Running Breadth-First-Search
        queue<int> q;
        q.push(idx1);
        vector<bool>visited(n);
        
        vector<int> dist(n); // to store number of moves required to reach each number
        dist[idx1] = 0; // initialize moves of starting number as zero
        visited[idx1] = 1; // mark starting number as visited
        
        while(!q.empty())
        {
            if(visited[idx2]) break;
            int node = q.front();
            q.pop();
            
            for(auto x: adj[node])
            {
                if(visited[x]) continue;
                
                dist[x] = dist[node] + 1;
                visited[x] = 1;
                q.push(x);
            }
        }
        
        return dist[idx2];
        
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends