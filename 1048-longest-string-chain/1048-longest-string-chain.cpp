class Solution {
private:

    bool psbl(string &a, string &b){
        if(a.size()!= b.size()+1) return false; 
        int f = 0, s = 0;
        
        while(f<a.size()){
            if(a[f] == b[s]) f++, s++;
            else f++;
        }
        
        return f == a.size() and s == b.size();
        
    }
    
static bool comp(string &a, string &b){
    return a.size()<b.size();
}
public:
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        
        vector<int> dp(n+1,1);
        int mx = 1;
        
        sort(arr.begin(), arr.end(),comp);
        
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(psbl(arr[i], arr[prev])) dp[i] = max(dp[i], 1 + dp[prev]);
            }
            
            mx = max(mx, dp[i]);
        }
            
            
         
        
        return mx;
    }
};