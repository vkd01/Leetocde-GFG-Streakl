class Solution {
private:
    bool check(vector<int> &arr, int mid){
        int n = arr.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]>=mid) count++;
            else break;
        }
        
        return count>=mid;
    }
public:
    int hIndex(vector<int>& arr) {
        int ans = 0, n = arr.size();
        
        
        int left = 0, right = 1e9+10;
        
        sort(arr.begin(),arr.end(), greater<int>());
        
        
        while(left<=right){
            
            int mid = left + (right - left)/2;
            
            
            if(check(arr,mid)){
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
            
            
        }
        
        
        
        
        return ans;
    }
};