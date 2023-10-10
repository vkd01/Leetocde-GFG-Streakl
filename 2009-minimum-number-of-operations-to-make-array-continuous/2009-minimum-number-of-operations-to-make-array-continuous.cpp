class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        vector<int> v;
        int n = nums.size();
        for(auto it : nums) st.insert(it);
        
        
        for(auto x : st) v.push_back(x);
        
        int ans = 1e9;
        
        for(int i=0;i<v.size();i++){
            int left=v[i];
            int right = n+left-1;
            
            auto it = upper_bound(v.begin(),v.end(),right);
            int remove = (it-v.begin())-i;
            ans=min(ans,n-remove);
        }
        return ans;
        
        
            
            
    }
};