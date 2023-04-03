//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    // Write your code here.
    int n = s.size();
    
    int a = 0, b = 0;
    
    if(s[0] == 'a') a++;
    else b++;
    
    for(int i = 1;i<n;i++){
        if(s[i] != s[i-1]) {
            if(s[i] == 'a') a++;
            else b++;
        }
    }
    
   
    return min(a,b) + 1;
    
}



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends