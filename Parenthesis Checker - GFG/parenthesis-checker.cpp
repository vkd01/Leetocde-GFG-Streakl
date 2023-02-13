//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code herestc
        stack<char> st;
        
        for(auto&i:s){
            if(i=='(') st.push(i);
            else if(i=='[') st.push(i);
            else if(i=='{') st.push(i);
            else if(i==')'){
                if(!st.empty() and st.top()=='(') st.pop();
                else st.push(i);
            }
            else if(i=='}'){
                if(!st.empty() and st.top()=='{') st.pop();
                else st.push(i);
            }
            else if(i==']'){
                if(!st.empty() and st.top()=='[') st.pop();
                else st.push(i);
            }
        }
        
        // string check = "";
        // while(!st.empty()){
        //     check+=st.top();
        //     st.pop();
        // }
        // cout<<check<<endl;
        
        return st.size()==0;
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends