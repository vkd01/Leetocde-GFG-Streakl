class Solution {
public:
#include <vector>

std::vector<int> getAverages(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> avgs(n, -1); 

    long long windowSum = 0;   
    int left = 0;             
 
    for (int i = 0; i <= 2 * k && i < n; i++) {
        windowSum += nums[i];
    }
    
  
    
   // cout<<windowSum<<endl;

     
    for (int i = k; i < n; i++) {
        
        if (i - k >= 0 and i+k<n)
         avgs[i] = static_cast<int>(windowSum / (2 * k+1));

        
        if (i - k >= 0 and i+k+1<n) {
            
            windowSum -= nums[left++]; 
            windowSum += nums[i + k+1];    
           
        }
         
        
    }

    return avgs;
}

};