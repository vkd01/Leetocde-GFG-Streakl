class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        
        int max_till= 0, max_profit = 0, profit = 0;
        
        
        int mn = INT_MAX, mx = 0;
        for(auto&i:arr){
            mn = min(mn,i);
            mx = max(mx, i);
            profit = max(profit, i - mn);
           // cout<<i<<" "<<mn<<endl;
        }
        ans = profit;
        
        return ans;
    }
};