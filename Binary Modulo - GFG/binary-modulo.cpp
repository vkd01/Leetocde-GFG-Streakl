//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
      int modulo(string s,int m)
        {
            //code here
            long long k =0, p =1;
            
            reverse(s.begin(),s.end());
            
            for(int i= 0;i<s.size();i++){
               k=(k+(s[i]-'0')*p)%m ; 
                 p=(p*2)%m ;
            }
            
                
            return k%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends