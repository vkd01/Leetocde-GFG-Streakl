//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(int arr[], int N, int X)
    {
        
        // Your code here
       vector<pair<int,int>>V(N);
       for(int i=0;i<N;i++){
           V[i]={arr[i],i};
       }
       sort(V.begin(),V.end());
       int low=0;
       int high =N-1;
       int min_ind = INT_MAX;
       int ans = INT_MAX;
       
       while(low<=high){
           int mid=(low+high)/2;
           if(V[mid].first==X){
                ans = min(ans,V[mid].second);
                high = mid-1;
           }
           else if(V[mid].first<X){
               low=mid+1;
               
           }
           else{
               high=mid-1;
           }
       }
       
       if(ans==INT_MAX) return -1;
       
       return ans;
       
       
       
       
       
       
        
    }

};




//{ Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

// } Driver Code Ends