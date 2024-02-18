#include <iostream>
#include <vector>

class InversionsCounter {
public:
    // Function to count inversions using merge sort
    int countInversions(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    // Function to merge two sorted subarrays and count inversions
    int merge(std::vector<int>& nums, int low, int mid, int high) {
        int inversions = 0;

        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            inversions += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
        
        return inversions;
    }

    // Function to perform merge sort and count inversions
    int mergeSort(std::vector<int>& nums, int low, int high) {
        int inversions = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;

            // Count inversions in left subarray
            inversions += mergeSort(nums, low, mid);

            // Count inversions in right subarray
            inversions += mergeSort(nums, mid + 1, high);

            // Merge the sorted subarrays and count inversions
            inversions += merge(nums, low, mid, high);
        }
        return inversions;
    }
};

 

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int ans;
        
        InversionsCounter invc;
        
        ans = invc.countInversions(nums);
        
        
        
        
        
        return ans;
    }
};









