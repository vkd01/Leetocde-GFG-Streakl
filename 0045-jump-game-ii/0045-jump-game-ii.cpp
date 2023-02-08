class Solution {
private:
    int dfs(vector<int>&nums,vector<int> &dp, int n, int ind){
        
        if(ind>=n-1) return 0;
         int ans = 1e8;
        if(dp[ind]!=-1) return dp[ind];
        for(int j = 1;j<=nums[ind];j++){
             int jump;
            if(ind+j<n){
                jump = 1 + dfs(nums,dp,n,ind+j);
                ans= min(ans,jump);
            }
            
            
        }
     //   cout<<ans<<endl;
        
        return dp[ind] = ans;
        
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> dp(n+1, -1);
        ans = dfs(nums,dp,n,0);
        
        
        return ans;
    }
};