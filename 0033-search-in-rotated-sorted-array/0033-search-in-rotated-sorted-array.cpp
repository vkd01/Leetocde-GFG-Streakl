class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int s=0,e=n-1;
        int mid;
        while(s<=e){
            mid = (s+e)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[s]<= nums[mid]){
                if(target >= nums[s] && target <= nums[mid]){
                    e = mid;
                }
                else{
                    s = mid+1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[e]){
                    s = mid + 1;
                }
                else{
                    e= mid-1;
                }
            }
        }
        return -1;
    }
};