//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s2,vector<string> s1){
        // Code here
        int ans = 0;
        
        
        
        unordered_map<string,int> mp;
        
        for(auto&i:s1) mp[i]++;
        
        
        for(auto&s:s2){
            string temp = "";
            
            bool found = true;
            
            for(int i = 0;i<s.size();i++){
                temp+=s[i];
                if(mp[temp]>0){
                    
                    found = true;
                    ans+=mp[temp];
                    mp[temp]= 0;
                   // break;
                }
            }
            
           // if(found) continue;
            
            temp = "";
            
            for(int i = s.size()-1;i>=0;i--){
                  temp+=s[i];
                  reverse(temp.begin(),temp.end());
                 // cout<<temp<<endl;
              if(mp[temp]>0){
                   
                    found = true;
                    ans+=mp[temp];
                     mp[temp]= 0;
                  //  break;
                }
                reverse(temp.begin(),temp.end());
            }
            
            
        }
        
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends