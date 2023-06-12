class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if(nums.size()==0){
            return {};
        }
        
        if(nums.size()==1) {
            string temp = to_string(nums[0]);
            return {temp};
        }
        
        
        
        
        int left = nums[0], right = nums[0];
  
        
        for(int i = 1;i<nums.size();i++){
            long long p = nums[i];
            long long q = nums[i-1];
            if(p - q==1){
                right++;
            }
            else{
                string a = to_string(left);
                string b = to_string(right);
                
                string temp = a + "->" + b;
                
                if(a==b) ans.push_back(a);
                else
                ans.push_back(temp);
                
                right = nums[i];
                left = right;
            }
        }
        
         long long p = nums[nums.size()-1];
         long long q = nums[nums.size()-2];
        
        if(p -q != 1){
            string a = to_string(nums[nums.size()-1]);
            string temp = a + "->" + a;
            ans.push_back(a);
        }
        
        else{
             string a = to_string(left);
                string b = to_string(right);
                
                string temp = a + "->" + b;
                
                if(a==b) ans.push_back(a);
                else
                ans.push_back(temp);
                
                
        }
        
        
        
        return ans;
    }
};