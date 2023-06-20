class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> ans(n,-1);
        
        vector<long long> prefix(n);
        
        prefix[0] = nums[0];
        
        for(int i = 1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];
        
        
        int left = 0, right = 2*k;
        
        while(right<n){
            
           int mid = (left + right)/2;
            
            long long sum;
            if(left==0) sum = prefix[right];
            else sum = prefix[right] - prefix[left-1];
                              
            long long avg = sum/(right - left+1);                  
            
            ans[mid] = avg;
            
            left++, right++;                  
                              
            
        }
         
        
        
        
        return ans;
    }
};