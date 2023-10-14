class Solution {
private:
    bool isArth(vector<int>&arr, int left, int right){
        
        
        int d = arr[left+1] - arr[left];
        
        for(int i = left+1;i<=right;i++){
            if(arr[i] - arr[i-1] != d) return false;
        }
        
        return true;
    }
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        int ans = 0, n = arr.size();
        
        
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(j-i+1<3) continue;
                
                if(isArth(arr, i, j)) ans++;
                
                
            }
        }
        
        
        return ans;
        
    }
};