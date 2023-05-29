class Solution {

private:
    
    int dfs(int ind, string &s, set<string> &dict, vector<int> &dp){
        if(ind == s.size()) return 0;
        
        
        if(dp[ind] != -1) return dp[ind];
        
        int ans = 1e9;
        
        for(int j = ind;j<s.size();j++){
            
            string temp = "";
            for(int i = ind;i<=j;i++) temp+=s[i];
            
            int cost = j - ind + 1;
            
            if(dict.find(temp) != dict.end()) cost = 0;
            
       
            ans = min(ans, cost + dfs(j + 1, s, dict,dp));
            
        }
        
        return dp[ind] = ans;
        
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int ans = 0;
        
        set<string> dict;
        for(auto&i:dictionary) dict.insert(i);
        
        vector<int> dp(s.size() + 2, -1);
        
        
        ans = dfs(0, s, dict, dp);
        
        
        
        return ans;
        
        
        
    }
};




