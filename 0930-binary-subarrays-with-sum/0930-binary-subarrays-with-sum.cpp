class Solution {
    
private:
    int countSubarrays(vector<int> &arr, int sum){
        if(sum<0) return 0;
        int prefix = 0, left = 0, ans = 0, n = arr.size();
        for(int i= 0;i<n;i++){
            prefix+=arr[i];
            while(prefix>sum){
                prefix-=arr[left];
                left++;
            }
             ans+=(i-left+1);
        }
        
        return ans;
    }
    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, n = nums.size();
        
        int x = countSubarrays(nums,goal);
        int y = countSubarrays(nums,goal-1);
        
        
       
        
        ans = x - y;
        
        
        return ans;
    }
};