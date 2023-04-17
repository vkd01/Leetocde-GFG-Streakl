class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        
        
        int mx = 0, n = candies.size();
        
        for(auto&i:candies) mx = max(mx,i);
        
        for(int i = 0;i<n;i++){
            if(candies[i] + extraCandies >= mx) ans[i] = true;
            else ans[i] = false;
        }
        
        
        
        return ans;
    }
};