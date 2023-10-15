class Solution {
private:
    bool check(int target, int mid){
        
        
        int times = 1;
        long long x = mid;
        
        long long so_far = x*(x+1)/2;
        
        return so_far>=target;
        
    }
public:
    int reachNumber(int target) {
        
        target = abs(target);
        
        
        int left = 1, right = target;
        
        
        long long ans = 0, rextreme = 0;
        
        while(left<=right){
            long long mid = left + (right - left)/2;
            
            if(check(target, mid)){
                ans = mid;
                rextreme = (mid*(mid+1))/2;
                right = mid-1;
            }
            else left = mid+1;
            
            
        }
        
        
        long long extra = rextreme - target;
        
        if(extra%2 == 0) return ans;
        
        if((ans+1)&1) ans+=1;
        else ans+=2;
        
        
        return (int)ans;
    }
};