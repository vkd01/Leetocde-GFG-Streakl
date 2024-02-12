class Solution {
private:
    int f(int ind, vector<int>&arr, int k, vector<int>&dp){
        if(ind==arr.size()) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int len = 0, mx = -1e5 + 10;
        int best_ans = -1e5 + 10;
        
        for(int j = ind;j<min((int)arr.size(), ind+k);j++){
            len++;
            mx = max(mx, arr[j]);
            int sum = len*mx + f(j+1, arr, k, dp);
            best_ans = max(best_ans, sum);
        }
        
        return dp[ind] = best_ans;
        
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        int ans = f(0,arr, k, dp);
        
        return ans;
    }
};