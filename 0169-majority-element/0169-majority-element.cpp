class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1, count = 0;
        
        for(auto&i:nums){
            if(i == ans) count++;
            else {
                if(count == 0){
                    count = 1;
                    ans = i;
                }
                else count--;
            }
        }
        
        return ans;
    }
};