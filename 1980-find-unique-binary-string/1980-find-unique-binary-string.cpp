class Solution {
    
private:
    void getAns(int ind, int n, string &temp, vector<string>&nums,map<string, int>&hash, string &ans){
        
        if(ind==n){
            if(hash[temp] == 0) ans = temp;
            return;
        }
        
        temp[ind] = '1';
        
        getAns(ind+1, n,temp,nums,hash, ans);
        
        temp[ind] = '0';
        
        getAns(ind+1, n, temp, nums, hash, ans);
        
        
        
        
        
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
    
        
        int n = nums.back().size();
        map<string, int> hash;
        
        
         string temp = nums[0];
        
        for(auto&i:nums) hash[i]++;
        string ans = "";
        
        getAns(0, n, temp,nums, hash, ans);
        
        
        
        return ans;
    }
};