//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    
	      int left = 0, right = 0;
        
        if(n==1) return;
        
        while(left<n and right<n){
            
           
            while(left<n and arr[left] != 0) left++;
            while(right < n and (right<left or  arr[right] == 0)) right++;
            // cout<<left<<" "<<right<<endl;
            
            if(left< n and right<n and right>left)
            swap(arr[left],arr[right]);
        }
        
        
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends