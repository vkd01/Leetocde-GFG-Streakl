class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int ans = 1e9;
        
        int left = 0, right = 0;
        
        int sum = 0, n = arr.size();
        
        while(right<n){
            while(right<n and sum<target){
                
                sum+=arr[right];
                right++;
                
            }
            
            if(sum>=target)
            ans = min(ans,right - left);
            
            //cout<<"Sum 1 "<<sum<<endl;
            
            while(left<n and sum>=target){
                sum-=arr[left];
                left++;
                if(sum>=target) ans = min(ans, right - left);
            }
            
           // cout<<"Sum 2 "<<sum<<endl;
            
            
           // cout<<left<<" "<<right<<endl;
            
        }
        
        
        if(ans == 1e9) ans = 0;
        
        return ans;
    }
};