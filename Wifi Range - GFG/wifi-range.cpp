//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        vector<int> visited(n+2,0),visited2(n+2,0);
        
        bool ok = true;
        
        
        for(int i = 0;i<n;i++){
            int ind = i+1;
            
           // cout<<ind<<" "<<ind+x+1<<endl;
            
            if(s[i]=='1'){
                visited[ind]++;
                visited[min(n+1,ind+x+1)]--;
            }
        }
       for(int i = 1;i<n+2;i++) visited[i]+=visited[i-1];
       
       
        //  for(int i = 0;i<n+2;i++) cout<<visited[i]<<" ";
        // cout<<endl;
        
        for(int i = n-1;i>=0;i--){
            int ind = i+1;
            if(s[i]=='1'){
                visited2[ind]++;
                visited2[max(0,ind-x-1)]--;
            }
        }
        for(int i = n-1;i>=1;i--) visited2[i]+=visited2[i+1];
        
        
        //  for(int i = 0;i<n+2;i++) cout<<visited2[i]<<" ";
        // cout<<endl;
        
        vector<int> check(n+2,0);
        
        for(int i = 0;i<n+2;i++) {
          //  cout<<visited[i]<<" "<<visited2[i]<<endl;
            if(visited[i]>0 or visited2[i]>0) check[i] = 1;
        }
        
        // for(int i =1 ;i<n+1;i++) cout<<check[i]<<" ";
        // cout<<endl;
        
        
        for(int i = 1;i<=n;i++) if(check[i]==0) ok = false;
        
        
        
        
        return ok;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends