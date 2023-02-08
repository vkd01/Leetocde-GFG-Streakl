//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    
    void rec(int i,vector<string> &ans, string &s){
        
      //   cout<<temp<<endl;
        if(i == s.size()){
            ans.push_back(s);
            return;
        }
        
        
       // temp.push_back(s[i]);
        
        for(int j = i;j<s.size();j++){
            if(s[j]==s[j+1]) continue;
            swap(s[i],s[j]);
            rec(i+1,ans,s);
            swap(s[i],s[j]);
        }
        
    
        
    }
    void permute(vector<string> &ans,string s,int ind){

         if(ind==s.size()){

             ans.push_back(s);

             return;

         }

         

         for(int i=ind;i<s.size();i++){

             if(s[i]==s[i+1])

             continue;

             

             swap(s[ind],s[i]);

             permute(ans,s,ind+1);

             swap(s[ind],s[i]);

         }

         

     }


 
    
    
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    string temp = "";
		    vector<string> ans;
		    rec(0,ans,s);
		    
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends