class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        
        
        for(auto&i:grid){
            auto lb = upper_bound(i.rbegin(),i.rend(),-1);
            
            ans+= (lb - i.rbegin());
        }
        
        
        return ans;
    }
};