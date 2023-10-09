class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans;
        
        int n = arr.size();
        
        int left = 0, right = n-1, first = -1, last = -1;
        
        while(left<=right){
            int mid = left + (right - left)/2;
            
            
            if(arr[mid] == target){
                first = mid;
                right = mid-1;
            }
            else if(arr[mid]>target) right = mid -1 ; 
            else left = mid+1;
        
        }
        
        ans.push_back(first);
        
        left = 0, right = n-1;
        
        while(left<=right){
            int mid = left + (right - left)/2;
            if(arr[mid] == target){
                last = mid;
                left = mid+1;
            }
            else if(arr[mid]<target) left = mid+1;
            else right = mid-1;
        }
        
        ans.push_back(last);
        
        
        return ans;
    }
};