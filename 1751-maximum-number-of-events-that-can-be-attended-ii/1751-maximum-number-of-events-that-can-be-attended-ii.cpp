class Solution {
private:
    
    int binary_search(int val,int ind, vector<vector<int>>&arr){
        
        int n = arr.size();
        int left = ind, right = n-1; 
        
        int ans = -1;
        
        int red = 100;
        
        while(left<=right){
            int mid = left + (right - left)/2;
            
           
            
            if(arr[mid][0] >val) {
                ans = mid;
                right = mid-1;
            }
            else left = mid +1;
            
        }
        
        return ans;
    }
    
    int rec(int ind, int k, vector<vector<int>>&arr, vector<vector<int>>&dp){
        
        if(ind>=arr.size() or k==0 or ind == -1) return 0;
        
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int bs = binary_search(arr[ind][1],ind+1, arr);
        
        //if(bs ==-1) return 0;
        
        int take = arr[ind][2] + rec(bs, k-1,arr,dp);
        int not_take = 0 + rec(ind+1, k,arr,dp);
        
        return dp[ind][k] =  max(take, not_take);
    
        
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        sort(events.begin(),events.end());
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        int ans = rec(0, k, events,dp);
        
        
        
        return ans;
    }
};