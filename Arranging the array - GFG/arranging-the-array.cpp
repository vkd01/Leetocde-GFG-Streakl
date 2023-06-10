//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
                void Rearrange(int arr[], int n)
        {
            // Your code goes here
           vector<int> temp;
           
           stack<int> st;
           
           for(int i = 0;i<n;i++){
               if(arr[i]<0) temp.push_back(arr[i]);
               else st.push(arr[i]);
           }
           
           vector<int> x;
           while(!st.empty()){
               x.push_back(st.top());
               st.pop();
           }
           
           reverse(x.begin(),x.end());
           
           for(auto&i:x) temp.push_back(i);
           
           
           
           for(int i = 0;i<n;i++) arr[i] = temp[i];
            
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends