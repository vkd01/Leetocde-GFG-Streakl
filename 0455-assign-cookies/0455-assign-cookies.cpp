class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        
        while(i<g.size() and j<s.size()){
            if(s[j]>=g[i]){
                ans+=1;
                i++;
            }
            j++;
        }
        
        
        
        
        
        return ans;
    }
};