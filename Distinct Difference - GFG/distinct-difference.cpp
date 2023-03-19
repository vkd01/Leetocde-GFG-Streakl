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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int> prefix(N), suffix(N);
        set<int> s;
        
        for(int i = 0;i<N-1;i++) {
            s.insert(A[i]);
            prefix[i+1] = s.size();
        }
        
        s.clear();
        for(int i = N-1;i>=1;i--){
            s.insert(A[i]);
            suffix[i-1] = s.size();
        }
        
        // for(auto&i:prefix) cout<<i<<" ";
        // cout<<endl;
        // for(auto&i:suffix) cout<<i<<" ";
        // cout<<endl;
        
        vector<int> ans(N);
        for(int i= 0;i<N;i++) ans[i] = prefix[i] - suffix[i];
        
        return ans;
        
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
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends