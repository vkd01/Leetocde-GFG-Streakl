class Solution {
    
private:
    int digSum(int n){
        int ans = 0;
        
        while(n){
            ans+=n%10;
            n/=10;
        }
        
        return ans;
    }
    
public:
    int addDigits(int num) {
        int ans = num;
        
        while(ans>9){
            ans = digSum(ans);
        }
        
        
        return ans;
    }
};