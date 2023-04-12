//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        int ans = 0;
        
        
        vector<int> left, right;
        
        
        for(int i = 0;i<n/2;i++) left.push_back(arr[i]);
        
        for(int i = n/2;i<n;i++) right.push_back(arr[i]);
        
        
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        
        
        
        for(auto&ii:right){
            int num = 5*ii;
            
            
            auto lb = lower_bound(left.begin(),left.end(), num);
            
            
            if(lb == left.begin()){
                if(*lb >= num) ans+=n/2;
                
               
            }
             else ans += (n/2 - (lb - left.begin()));
            
            
        }
        
        
        
        return ans;
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
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends