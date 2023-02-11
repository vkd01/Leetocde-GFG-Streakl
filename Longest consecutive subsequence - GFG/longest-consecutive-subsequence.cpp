//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      int ans = 0, temp  =0;
      vector<int> hash(1000008,0);
      
      for(int i = 0;i<n;i++){
          hash[arr[i]]++;
      }
      
      for(int i = 0;i<1000008;i++){
          if(hash[i]!=0 )temp++;
          else {
              ans = max(ans,temp);
              temp = 0;
          }
      }
      ans = max(ans,temp);
      return ans;
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends