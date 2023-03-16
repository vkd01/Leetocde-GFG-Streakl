//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        int count = 0;
        
        if(S>=D*9) return "-1";
        if(D == 1) return to_string(S);
        
        
        string a;
        int temp = S-1;
        for(int i=0;i<D;i++){
            if(temp>=9){
                a += "9";
                temp-=9;
            }
            else{
                a += to_string(temp);
                temp = 0;
            }
        }
        int cnt = a.back() - '0' + 1;
        a.pop_back();
        a += to_string(cnt);
        reverse(a.begin(),a.end());
        
        char pre = a.back();
        for(int i=a.size()-2;i>=0;i--){
            if(pre != a[i]){
                a[i] = a[i]-'0' + 1 + '0';
                a[i+1] = a[i+1]-'0'-1 + '0';
                break;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends