//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
       int arrayOperations(int n, vector<int> &arr) {
        // code here
        int nonzero = 0, zero =0,seg = 0;
        
        for(int i = 0;i<n;i++){
            if(arr[i]==0){
                if(nonzero>0){
                    seg++;
                    nonzero=0;
                } 
            }
            else {
                nonzero++;
            }
        }
        if(nonzero>0) seg++;
        
        if(nonzero==n) return -1;
       // else if(nonzero==0) return 0;
        
        else return seg;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends