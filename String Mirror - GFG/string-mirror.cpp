//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  string stringMirror(string str){
        // Code here
         // code here
    string prefix = "";
    prefix += str[0];
    
    for (int i = 1; i < str.length(); i++) {
        char currentChar = str[i];
        char previousChar = str[i - 1];
        if (currentChar > previousChar) {
            break;
        }
        if (currentChar == str[0]) {
            break;
        }
        prefix += currentChar;
    }
    
    string mirroredPrefix = prefix;
    string reversedPrefix = string(mirroredPrefix.rbegin(), mirroredPrefix.rend());
    mirroredPrefix += reversedPrefix;
    
    return mirroredPrefix;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends