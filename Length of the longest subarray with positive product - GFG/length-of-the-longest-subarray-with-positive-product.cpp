//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &nums,int n){
           //code here
          // int n = nums.size();
           int ans = 0;
           
           for(int i = 0;i<n;i){
               int s = i;
               while(s<n and nums[s]==0) s++;
               int e= s;
               int c = 0;
               int sn = -1 , en = -1;
               while(e<n and nums[e]!=0){
                   if(nums[e]<0){
                       c++;
                       if(sn==-1) sn = e;
                       en = e;
                   }
                   e++;
               }
               if(c%2==0) ans = max(ans,e-s);
               else {
                   if(sn!=-1) ans = max(ans,e - sn - 1);
                   if(en!=-1) ans = max(ans, en - s);
               }
               i = e+1;
           }
           
           return ans;
           
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends