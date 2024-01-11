class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = 0;
        
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int n = nums.size();
        
        int left = -1, right = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] != sorted[i]) {
                (left == -1) ? left = i : right = i;
            }
        }
        
        if(left == -1 and right == -1) return 0;
        
        ans = right - left + 1;
        
        
        return ans;
    }
};