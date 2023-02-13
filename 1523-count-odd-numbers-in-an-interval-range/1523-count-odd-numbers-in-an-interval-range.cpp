class Solution {
public:
    int countOdds(int low, int high) {
        
        if(high-low==0){
            if(low&1) return 1;
            return 0;
        }
    
        
        int diff = high-low;
        
        if(low&1 and high%2==0){
            return (diff+1)/2;
        }
        else if(low%2==0 and high&1){
            return (diff+1)/2;
        }
        else if(low%2==0 and high%2==0){
            return diff/2;
        }
        
        else if(low&1 and high&1){
            return diff/2 + 1;
        }
        
        
       return 89; 
        
    }
};