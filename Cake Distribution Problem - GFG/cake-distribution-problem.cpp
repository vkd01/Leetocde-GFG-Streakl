//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    
    bool check(vector<int> &arr, int k, int mid){
        int chops = 0, sum = 0;
        
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>=mid) {
                chops++;
                sum = 0;
            }
        }
        return chops>=k+1;
    }
    
    public:
    int maxSweetness(vector<int>& arr, int n, int k) {
    // Write your code here.
    
    
    int low = *min_element(arr.begin(),arr.end());
    int high = 0;
    for(auto&i:arr) high+=i;
    int ans = -1e9;
    
    while(low<=high){
        int mid = low + (high - low)/2;
        
        
        bool ok = check(arr,k, mid);
        
       if(ok) {
           low = mid+1;
           ans = mid;
       }
       else high = mid - 1;
        
        
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
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends