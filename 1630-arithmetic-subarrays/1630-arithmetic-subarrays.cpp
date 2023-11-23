class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        
        for(int i = 0;i<l.size();i++){
            
            
            int x = l[i], y = r[i];
            
            bool isSame = true;
            
            vector<int> temp;
            
            for(int j = x;j<=y;j++) temp.push_back(nums[j]);
            
            sort(temp.begin(), temp.end());
            
            for(int j = 1;j<temp.size();j++) isSame&=(temp[j] - temp[j-1] == temp[1] - temp[0]);
            
            
            ans.push_back(isSame);
            
        }
        
        
        return ans;
    }
};