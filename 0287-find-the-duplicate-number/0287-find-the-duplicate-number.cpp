class Solution {
private:
    
    
    bool check(vector<int>&arr, int mid){
        
        
        int count = 0;
        
        
        
        for(int i = 0;i<arr.size();i++){
            
            if(arr[i]<=mid) count++;
        }
        
        
        return count<=mid;
    }
    
    
    
public:
    int findDuplicate(vector<int>& nums) {
        
        
        int n = nums.size();
        
        int left = 1, right = n;
        
        int ans = -1;
        
        while(left<=right){
            
            int mid = left + (right - left)/2;
            
         //   cout<<mid<<endl;
            
            if(check(nums, mid)){
               
                left = mid+1;
            }
            else {
                 ans = mid;
                right = mid-1;
            }
            
        }
        
        if(ans==-1) return nums.back();
        
        return left;
    }
};