class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), mx = 0, end = 0;
        
        for(int i = 0;i<n;i++){
            mx = max(mx, i + nums[i]);
            if(i==end){
                end = mx;
            }
        }
        
        
        
        return end>=n-1;
    }
};