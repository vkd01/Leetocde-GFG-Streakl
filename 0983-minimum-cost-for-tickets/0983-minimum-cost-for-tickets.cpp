class Solution {

private:
    int rec(int ind,int n, vector<int>&days, vector<int> &costs, vector<int> &dp){
        if(ind >= n) {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        
        int i;
        
       
        
        int pass1 = costs[0] + rec(ind+1,n, days, costs, dp);
        
        for(i = ind; i<n and days[i] < days[ind] + 7;i++);
        
        int pass2 = costs[1] + rec(i, n, days, costs, dp);
        
         for(i = ind; i<n and days[i] < days[ind] + 30;i++);
        
        int pass3 = costs[2] + rec(i, n, days, costs, dp);
        
        return dp[ind] = min({pass1, pass2, pass3});
        
        
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int ans = 0;
        int n = days.size();
        
        vector<int> dp(n+1,-1);
        
        ans = rec(0,n,days,costs,dp);
        
        
        return ans;
    }
};



