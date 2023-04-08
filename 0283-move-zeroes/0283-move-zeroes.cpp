class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int left = 0, right = 0, n = arr.size();
        
        if(n==1) return;
        
        while(left<n and right<n){
            
           
            while(left<n and arr[left] != 0) left++;
            while(right < n and (right<left or  arr[right] == 0)) right++;
            // cout<<left<<" "<<right<<endl;
            
            if(left< n and right<n and right>left)
            swap(arr[left],arr[right]);
        }
        
        
    }
};