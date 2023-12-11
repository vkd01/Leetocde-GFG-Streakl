class Solution {
private:
    bool check(vector<int>&arr, int mid, int k){
        
        int segment = 1;
        
        int sum = 0;
        
        for(auto&i:arr){
            if(i>mid) return false;
             
            if(sum+i<=mid){
                sum+=i;
            }
            else{
                segment++;
                sum = i;
            }
        }
        
        
        return segment<=k;
        
        
    }
public:
    int splitArray(vector<int>& arr, int k) {
        
        
        int ans = 0;
        
        
        
        int left = 0, right = 1e9 + 10;
        
        
        while(left<=right){
            
            int mid = left + (right - left)/2;
            
            if(check(arr, mid,k)){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
            
              
        }
        
        
        return ans;
    }
};