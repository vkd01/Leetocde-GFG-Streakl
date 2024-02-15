class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        long long ans = -1, sum = nums[0]+nums[1] + nums[2];
        
        long long mx = max({nums[0], nums[1], nums[2]});
        
        
        
        if(mx<sum-mx) ans = max(ans, sum);
        
        for(int i = 3;i<(int)nums.size();i++){
            mx = max(mx, (long long)nums[i]);
            
            sum+=nums[i];
            
           // cout<<mx<<" "<<sum<<endl;
            
            if(mx<sum-mx){
                ans = max(ans, sum);
            }
            
        }
        
        return ans;
    }
};