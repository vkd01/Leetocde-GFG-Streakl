//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
string removePair(string s) {

        string ans="";

        for(char ch:s){

            if(!ans.empty() && ans[ans.size()-1]==ch)                               ans.pop_back();

            else ans +=ch;

        }

     return ans.size()==0 ? "-1":ans;

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends