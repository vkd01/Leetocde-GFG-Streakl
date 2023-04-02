class Solution {
public:
    int minOperations(int n) {
        int setbits = 0;
        
        int ans = 0;
        
        for(int i = 0;i<31;i++){
            if((1<<i)&n) setbits++;
            else{
                if(setbits == 1) ans++, setbits = 0;
                else if(setbits>1) ans++, setbits = 1;
            }
        }
        
        if(setbits==1) ans++;
        else if(setbits>1) ans+=2;
       
        
       return ans;
    }
};