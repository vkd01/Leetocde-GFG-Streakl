//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> arr) {
        // code here
        long long sum = 0;
        vector<long long> dp;
        for(int i = 0;i<k;i++){
            sum+=arr[i];
            dp.push_back(arr[i]);
        }
        dp.push_back(sum);
        for(int i = k;i<=n;i++){
            sum+=dp[i];
            sum-=dp[i-k];
            dp.push_back(sum);
        }
        
        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends