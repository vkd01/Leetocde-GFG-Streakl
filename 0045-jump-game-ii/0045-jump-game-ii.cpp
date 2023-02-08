class Solution {
private:
    void dfs(vector<int> &nums, int i, int j, int n , int m){
       
        
        
        
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, ans = 0, curr = 0;
        
        for(int i = 0;i<n-1;i++){
            mx = max(mx,i+nums[i]);
            if(i == curr){
                ans++;
                curr = mx;
            }
        }
        
        
        
        return ans ;
    }
};