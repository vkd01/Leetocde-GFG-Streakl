//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        long long ans = INT_MIN;
        
        
        int mx = 0;
        
        for(int i =0;i< lines.size();i++){
            for(int j = 0; j< lines[0].size();j++){
                mx = max(mx,lines[i][j]);
            }
        }
        
        
        map<long long , long long> diff;
        
        for(auto&i:lines){
            long start =i[0];
            long end = i[1];
            
            diff[start]++;
            diff[end+1]--;
        }
        
        
        long long prefix = 0;
       
       for(auto&i:diff){
           prefix+=i.second;
           
           ans = max(ans, prefix);
       }
        
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends