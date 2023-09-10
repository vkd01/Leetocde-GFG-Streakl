class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int need;
        int yco = abs(sy - fy);
        int xco = abs(sx - fx);
        
        need  = max(xco, yco);
        
        cout<<need<<endl;
        
        if(need == 0) {
            if(t==1) return false;
            return true;
        }
        if(need>t) return false;
    
        
        
        return true;
    }
};