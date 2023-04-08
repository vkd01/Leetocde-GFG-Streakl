class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zero = 0;
      
        for(auto&i:nums) if(i==0) zero++;
          if(zero==0) return;
        int n = nums.size();
        if(n==1) {
            if(nums[0]==0) return;
            else  return;
            
        }
        if(n==2){
            if(nums[0]==0){
                swap(nums[0],nums[1]);
                return;
            }
            else return;
        }
        int ptr1 = 0,ptr2 = 0;
        
        while(ptr2<n){
            while(nums[ptr1]!=0) ptr1++;
            if(nums[ptr2]==0) {
                while(nums[ptr2]==0) {
                    ptr2++;
                    if(ptr2>=n-1) break;
                }
                if(ptr2<=n-1)
                swap(nums[ptr1],nums[ptr2]);
                //ptr1++;
            }
            else ptr2++;
        }
        for(int i=n-zero;i<n;i++) nums[i] = 0;
    }
};