//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int> mp;
        
        
        for(auto&i:arr) mp[i]++;
        
        for(auto&s:arr){
            string temp = s;
            reverse(temp.begin(),temp.end());
            
            if(mp[temp]>0){
                mp[s]--;
                mp[temp]--;
            }
        }
        
        int remain = 0;
        for(auto&i:mp){
            if(i.second>0){
                string temp = i.first;
                reverse(temp.begin(),temp.end());
                if(temp!=i.first) return false;
                remain++;
            }
        }
        
        return remain<2;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends