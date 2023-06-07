class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        
        
        for(int i = 31;i>=0;i--){
            if((1<<i)&c){
                
                if(((1<<i)&a) or ((1<<i)&b)) {
                    
                }
                else ans++;
                
                
            }
            
            else{
                if(((1<<i)&a)) ans++;
                
                if(((1<<i)&b)) ans++;
            }
        }
        
        
        
        return ans;
    }
};