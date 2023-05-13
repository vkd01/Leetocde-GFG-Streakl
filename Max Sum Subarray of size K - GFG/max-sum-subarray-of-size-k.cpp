//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long long sum = 0;
        long long ans = 0;
        
        
        int left=0,right=k-1;
        for(int i=0;i<=right;i++)
        sum+=arr[i];
        
        ans=max(ans,sum);
        
        
        while(right+1<n){
            sum-=arr[left];
            left++;right++;
            sum+=arr[right];
             ans=max(ans,sum);
           //  cout<<sum<<endl;
        }
       
            ans=max(ans,sum);
        
        return ans;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends