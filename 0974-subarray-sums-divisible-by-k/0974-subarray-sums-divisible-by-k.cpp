class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> remainder;
        int ans = 0, n = nums.size(),sum = 0;
        remainder[0]++;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) rem+=k;
            if(remainder.find(rem)==remainder.end()) remainder[rem]++;
            else{
                ans+=remainder[rem];
                remainder[rem]++;
            }
        }
        return ans;
    }
};