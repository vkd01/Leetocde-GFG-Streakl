//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &arr,int n)
        {
            // Code here
            vector<int> temp;
            vector<vector<int>> ans;
            temp.push_back(arr[0]);
            int prev = arr[0];
            
            for(int i = 1;i<n;i++){
              //  cout<<prev<<" "<<arr[i]<<endl;
                if(arr[i]%2 == prev%2) temp.push_back(arr[i]);
                else {
                    
                    sort(temp.begin(),temp.end());
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                    temp.clear();
                    temp.push_back(arr[i]);
                }
                prev = arr[i];
            }
            if(temp.size()){
                sort(temp.begin(),temp.end());
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            
            // for(auto&i:ans){
            //     for(auto&j:i) cout<<j<<" ";
            //     cout<<endl;
            // }
            
            vector<int> fuck;
            
            for(auto&i:ans){
                for(auto&j:i) fuck.push_back(j);
            }
            
            
            
            return fuck;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends