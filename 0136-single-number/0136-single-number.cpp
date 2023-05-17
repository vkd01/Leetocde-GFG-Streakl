class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = 0;
        for(auto&i:arr) ans^=i;
        
        
        
        return ans;
    }
};