class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        
        int need = max(abs(sx-fx), abs(sy-fy));
        
        if(need>t) return false;
        
        if(need==0 and t==1) return false; 
        
        return true;
        
    }
};