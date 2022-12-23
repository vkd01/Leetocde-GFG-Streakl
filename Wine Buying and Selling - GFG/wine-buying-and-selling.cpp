//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
long long int wineSelling(vector<int>& a, int N){

      //Code here.

      long long int s=0;

      long long int b=0;

      long long int ans=0;

      while(s<a.size() && b<a.size())

      {

          while((a[b]<=0))

          {

              b++;

              if(b==a.size())return ans;

          }

          while((a[s]>=0))

          {

              s++;

               if(s==a.size())return ans;

          }

          int temp=a[s]+a[b];

          if(temp>0)

          {

              ans+=abs(a[s])*abs(s-b);

              a[s]=0;

              a[b]=temp;

          }

          else

          {

              ans+=abs(a[b])*abs(s-b);

              a[s]=temp;

              a[b]=0;

          }

      }

      return ans;

  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends