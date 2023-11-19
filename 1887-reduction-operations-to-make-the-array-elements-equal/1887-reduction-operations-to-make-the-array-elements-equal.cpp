class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        
        
        int count = 1;
        
        
        for(int i = n-1;i>=1;i--){
            if(nums[i] != nums[i-1]){
                ans+=count;
            }
            count++;
        }
        
        
        return ans;
        
    }
};