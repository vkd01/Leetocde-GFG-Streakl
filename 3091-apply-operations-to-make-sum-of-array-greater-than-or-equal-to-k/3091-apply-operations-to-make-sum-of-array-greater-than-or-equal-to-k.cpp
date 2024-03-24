class Solution {
public:
    int minOperations(int k) {
        
        int ans = 1e9 + 10;
        
        for(int i = 1;i<1000;i++){
            for(int j = 0;j<1000;j++){
                int sum = i*j;
                if(sum>=k) ans = min(ans, i+j-1-1);
            }
        }
        
        
        return ans;
        
    }
};