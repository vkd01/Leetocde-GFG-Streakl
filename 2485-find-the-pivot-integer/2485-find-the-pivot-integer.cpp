class Solution {
public:
    int pivotInteger(int n) {
        
        int total = n*(n+1)/2;
        
        int low = 1, high = n, ans = -1;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            
            int left_sum = mid*(mid+1)/2;
            
            int right_sum = total - left_sum + mid;
            
          //  cout<<mid<<" "<<left_sum<<" "<<right_sum<<endl;
            
            if(left_sum == right_sum) return mid;
            
            if(left_sum<right_sum) low = mid + 1;
            else high = mid-1;
            
            
        }
        
        
        return -1;
    }
};