//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int a, int b, int c){
        // code here
        if(c==0){
            return a==b;
        }
        
        if(((b-a)<0 and c>0) or ((b-a)>0 and c<0)) return 0;
        
        if((b-a)%c==0) return 1;
        
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends