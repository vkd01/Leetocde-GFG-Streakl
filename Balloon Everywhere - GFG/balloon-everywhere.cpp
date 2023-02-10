//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
         map<char,int> map;
         
         for(auto&i:s) map[i]++;
         
         int ans = 0;
         
         int mn = 0;
         
         mn = min({map['b'],map['a'],map['l']/2, map['o']/2,map['n']});
         
        ans = mn;
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends