class Solution {
public:
    int numberOfMatches(int n) {
        
        int teams = n, ans = 0;
        
        while(teams>1){
            ans+=teams/2;
            teams = (teams+1)/2;
        }
        
        
        return ans;
    }
};