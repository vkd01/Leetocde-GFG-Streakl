//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        
          sort(ranges.begin(), ranges.end());
        int res = 0;
        
        vector<int> right(n);       // to store right max
        int m = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            m = max(m, ranges[i][2]);
            right[i] = m;
        }
        
        res = max(res, right[0]);
        for(int i = 0; i < n; i++){
            int start = ranges[i][0], end = ranges[i][1], coin = ranges[i][2];
            
            int low = i+1, high = n-1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(ranges[mid][0] < end){ // overlapping
                    low = mid + 1;
                }else{
                    // non-overlapping
                    res = max(res, coin + right[mid]);
                    high = mid - 1;
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends