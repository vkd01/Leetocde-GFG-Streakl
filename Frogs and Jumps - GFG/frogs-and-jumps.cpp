//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        
        vector <int> vist(100005,0);
        
        int fg=1;
        
        for(int i=0;i<n;i++){
            int x = frogs[i];
            if(x==1)return 0;
            if(vist[x]==0)
            {
            for(int j=x;j<=leaves;j+=x){
                vist[j]++;
            }
            }
        }
        
        int cnt=0;
        
        for(int j=1;j<=leaves;j++){
            if(vist[j]==0)cnt++;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends