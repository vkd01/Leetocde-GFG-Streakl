//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    #define ll long long
    private:
    int binpow(ll a, ll n) {
        ll res = 1LL; if (n == 0) return 1LL; while (n > 0) { 
            if (n & 1) res *= a; n >>= 1; a *= a; } return res; }
  public:
    string armstrongNumber(int n){
        // code here
        ll nn = n,store = n;
        bool ans = false;
        ll sum = 0;
        
        ll count = 0, cn = n;
        while(cn>0){
            cn/=10;
            count++;
        }
        
        while(nn>0){
           ll unit = nn%10;
           sum+=binpow(unit,count);
           nn/=10;
        }
        
        
        string check;
         if(sum==store) check = "Yes";
         else check = "No";
        
        return check;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends