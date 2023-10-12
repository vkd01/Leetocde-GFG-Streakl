/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int find_peak(MountainArray arr){
        
        int left = 1, right = arr.length() - 2;
        
        while(left<right){
            int mid = left + (right - left)/2;
            
            if(arr.get(mid)>arr.get(mid+1)) right = mid;
            else left = mid+1;
        }
        
        return right;
        
    }
    
    int binary_search_left(MountainArray arr, int target, int left, int right){
        
        while(left<=right){
            int mid = left + (right - left)/2;
            
            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) <target) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
        
    }
    
    int binary_search_right(MountainArray arr, int target, int left, int right){
        
        while(left<=right){
            int mid = left + (right - left)/2;
            
            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) >target) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
        
    }
    
    
    
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
         
        int peak = find_peak(mountainArr);
        
        
        int n = mountainArr. length();
        
        int left_ans = binary_search_left(mountainArr, target, 0, peak);
        
        int right_ans = binary_search_right(mountainArr, target, peak+1, n-1);
        
        
        if(left_ans != -1) return left_ans;

        
        
        
        return right_ans;
    }
};






