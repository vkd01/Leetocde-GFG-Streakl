class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        
        
        
        long long temp  = 0;
        
        for(auto&i:nums){
            if(i==0) temp++;
            else {
                ans += (temp*(temp+1))/2;
                temp = 0;
            }
        }
    
        ans += (temp*(temp+1))/2;
        
        
        return ans;
    }
};