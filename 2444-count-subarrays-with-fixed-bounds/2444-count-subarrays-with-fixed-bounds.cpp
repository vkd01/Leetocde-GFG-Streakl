class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long mn = -1,mx = -1, ptr = 0, n = nums.size(),ans = 0;
        
        for(int i = 0;i<n;i++){
            if(nums[i]==minK) mn = i;
            if(nums[i]==maxK) mx = i;
            
            if(nums[i]<minK or nums[i]>maxK) ptr = i+1;
            
            
            ans+=max(0LL, min(mn,mx)- ptr + 1);
        }
        
        return ans;
    }
};