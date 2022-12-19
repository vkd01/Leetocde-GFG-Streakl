int mod=1e9+7;
class Solution {
private:
    #define ll long long
 
    ll kadane(vector<int> &arr){
        int n = arr.size();
        ll ans = INT_MIN, max_ending_here = 0;
        for(int i =0;i<n;i++){
            ans = max(ans, max_ending_here);
            max_ending_here += arr[i];
            ans = max(ans, max_ending_here);
            max_ending_here = max(0LL,max_ending_here);
        }
        
        return ans%mod;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        
        ll sum = 0;
        ll ans1 = kadane(arr),ans2 = 0, ans3 = 0;
        
        if(k==1){
            return ans1;
        }
        
 
        for(auto&i:arr) sum +=i;
   
        
        ll prefix = 0, suffix = 0,temp = 0, n = arr.size();
        
        for(int i = 0;i<n;i++){
            temp  +=arr[i];
            prefix = max(prefix,temp);
        }
        temp = 0;
        for(int i = n-1;i>=0;i--){
            temp +=arr[i];
            suffix = max(suffix,temp);
        }
        
         ans2 = prefix + suffix + sum*(k-2);
        
         ans3 = (prefix + suffix);
        
        // cout<<prefix<<" "<<suffix<<endl;
       // cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
        
        return max({ans1,ans2,ans3})%mod;
        
    }
};













