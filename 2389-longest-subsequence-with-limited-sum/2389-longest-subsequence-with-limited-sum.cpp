class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        vector<int> ans,prefix(n);
        sort(nums.begin(),nums.end());
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];
        
        int qs = queries.size();
        
        for(int i= 0;i<qs;i++){
            int x = upper_bound(prefix.begin(),prefix.end(),queries[i]) - prefix.begin();
            
            ans.push_back(x);
        }
        
        
        return ans;
    }
};