class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int left = 0, right = 0, sum = 0;
        
        
        while(right<n){
            
            left = max(left,right);
            
            while(left<n and sum<=k){
                if(nums[left]==0) {
                    if(sum==k) break;
                    sum++;
                    
                }
                left++;
            }
            ans = max(ans,left-right);
            
             if(nums[right]==0 and sum>0) sum--;
                 right++;
        }
        
        
        
        return ans;
    }
};