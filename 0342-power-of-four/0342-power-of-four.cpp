class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==2) return false;
        int set_bits = 0;
        
        for(int i = 0;i<31;i++){
            if((1<<i)&n) set_bits++;
        }
        
        if(!(n & 0xaaaaaaaa) and set_bits == 1) return true;
        
        return false;
    }
};