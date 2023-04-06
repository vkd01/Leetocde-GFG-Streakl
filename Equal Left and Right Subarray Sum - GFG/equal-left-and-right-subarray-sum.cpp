//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &A) {
        
        if(n==1) return 1;
        
        if(n==2){
            if(A[0] == 0) return 2;
            else if(A[1] == 0) return 1;
        }
        // code here
        vector<int> prefix(n), suffix(n);
        prefix[0] = A[0];
        for(int i= 1;i<n;i++) prefix[i] = prefix[i-1] + A[i];
        
        suffix[n-1] = A[n-1];
        
        for(int i = n-2;i>=0;i--) suffix[i] = suffix[i+1] + A[i];
        
        
       // if(prefix[0]==suffix[1]) return 1;
        
        for(int i = 1;i<n-1;i++) if(prefix[i-1] == suffix[i+1]) return i+1;
        
       // if(suffix[n-1] == prefix[n-2]) return n-1;
        
        
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends