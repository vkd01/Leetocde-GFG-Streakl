//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
                vector<int> arr;
        
        for(int i = 0;i<N;i++) arr.push_back(A[i]);
        
        priority_queue<int> pq;
        
        long long ans = 0;
        
        for(int i = 0;i<N;i++) pq.push(A[i]);
        
        while(K--){
            int x = pq.top();
            ans+=x;
            pq.pop();
            pq.push(x/2);
        }
        
        
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends