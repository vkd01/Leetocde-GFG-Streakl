#define ll long long
const ll MOD = 1e9 + 7;

class Solution {
public:
    int n;
    ll dp[5001][7][20];
private:
    
    ll dfs(int i, int prev, int count, vector<int> &arr){
        
        if(i==n) return 1;
        
        if(dp[i][prev][count] != -1) return dp[i][prev][count];
        
        ll ans = 0;
        
        for(int curr = 1;curr<=6;curr++){
            if(curr == prev) {
                if(count+1<=arr[curr-1]) ans = (ans+dfs(i+1, prev, count+1, arr))%MOD;
            }
            else ans = (ans + dfs(i+1, curr, 1, arr))%MOD;
        }
        
        
        return dp[i][prev][count] = ans%MOD;
        
        
    }
    
public:
    int dieSimulator(int n_, vector<int>& arr) {
       
        n = n_;
        memset(dp, -1, sizeof(dp));
        ll ans = dfs(0,0,0,arr);
        
        return (int)ans;
    }
};










