class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9+10;
        int n = nums.size();
        
        int left = 0, right = 0;
        
        int sum = 0;
        
        while(right<n and left<n){
            while(right<n and sum<target){
                sum+=nums[right];
                right++;
            }
            
            while(sum>=target and left<n){
                sum-=nums[left];
                left++;
                ans = min(ans,right - left+1);
            }
        }
        
        if(ans==1e9+10) return 0;
        
        
        return ans;
    }
};