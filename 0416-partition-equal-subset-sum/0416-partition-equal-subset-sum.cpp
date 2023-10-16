class Solution {
private:
    
    bool rec(int ind, int &sum, int &curr, vector<int> &arr, vector<vector<int>>&dp){
        
      //  cout<<curr<<" "<<sum<<endl;
        
        if(ind>=arr.size()) return false;
        
        if(sum == curr) return true;
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        sum-=arr[ind];
        curr+=arr[ind];
        
        bool take = rec(ind+1, sum,curr, arr,dp);
        
        sum+=arr[ind];
        curr-=arr[ind];
        
        bool not_take = rec(ind+1, sum, curr, arr,dp);
        
        
        return dp[ind][sum] =  take or not_take;
        
        
    }
    
    
public:
    bool canPartition(vector<int>& arr) {
        
        int sum = 0, n = arr.size();
        
        for(auto&i:arr) sum+=i;
        
        if(sum&1) return false;
        
        int curr = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+100,-1));
        
        bool ok = rec(0,sum, curr,arr,dp);
        
        
        
        return ok;
        
    }
};