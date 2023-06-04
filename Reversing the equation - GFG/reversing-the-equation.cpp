//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans = "";
            
            
            int i = s.size()-1;
            string temp = "";
            
            while(i>=0){
            
            while(i>=0 and s[i]>='0' and s[i]<='9'){
                temp+=s[i];
                i--;
            }    
            
            reverse(temp.begin(),temp.end());
            
            ans+=temp;
            
            if(i>=0){
                ans+=s[i];
                i--;
            }
               
               temp.clear(); 
                
            }
            
            
            
            return ans;
        }
};



//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends