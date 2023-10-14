class Solution {
private:
    bool check(int n , int m , int mid, int k){
        
        int ans = 0;
    
        mid--;
        for(int i = 1;i<=n;i++){
            ans += min(mid/i, m);
        }
        
        return ans<k;
        
    }
public:
    int findKthNumber(int m, int n, int k) {
        int ans = 0;
        
        
        int left = 0, right = n*m+1;
        
        while(left<=right){
            int mid = left + (right -left)/2;
            if(check(m,n,mid,k)){
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        
        
        return ans;
        
    }
};