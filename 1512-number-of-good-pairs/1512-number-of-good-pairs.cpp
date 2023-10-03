class Solution {
public:
    int numIdenticalPairs(vector<int>& arr) {
        map<int,int> mp;
        
        int ans = 0;
        
        for(auto&i:arr){
            ans+=(mp[i]);
            
            mp[i]++;
        }
        
        return ans;
        
    }
};