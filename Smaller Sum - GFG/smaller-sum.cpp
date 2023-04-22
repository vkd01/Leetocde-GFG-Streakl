//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans(n);
        
        
        vector<long long> prefix(n),fuck;
        
        for(int i = 0;i<n;i++) prefix[i] = arr[i];
        
        sort(prefix.begin(),prefix.end());
        
        fuck = prefix;
        
        for(int i = 1;i<n;i++) prefix[i]+=prefix[i-1];
        
        
        for(int i = 0;i<n;i++){
            auto it = lower_bound(fuck.begin(),fuck.end(), arr[i]);
             int ind = it - fuck.begin();
             if(it == fuck.end()) it--;
            if(it == fuck.begin()) ans[i] = 0;
           
            else ans[i] = prefix[ind-1];
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends