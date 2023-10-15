class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        
         int ans = 0,n = arr.size();
        
        vector<map<long long,long>> dp(n+1);
        
       
        
        for(int i = 0;i<n;i++){
            for(int j = i-1;j>=0;j--){
                long long x = arr[i];
                long long y = arr[j];
                long long diff = x - y;
                
                dp[i][diff]++;
                
                dp[i][diff]+=dp[j][diff];
                
                ans+=dp[j][diff];
                
                
                
                
                
            }
        }
        
        
        return ans;
        
    }
};