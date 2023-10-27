class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        
        
        int left = -1, right = -1, len = 0;
        
        int x,y, n = s.size();
        
        for(int i = 0;i<n;i++){
            x = i-1;
            y = i+1;
            
            while(x>=0 and y<n and s[x] == s[y]){
                if(y - x + 1>len){
                    len = y - x+1;
                    left = x;
                    right = y;
                }
                
                x--;
                y++;
            }
            
            x = i+1;
            y = i;
            
              while(x>=0 and y<n and s[x] == s[y]){
                if(y - x + 1>len){
                    len = y - x+1;
                    left = x;
                    right = y;
                }
                
                x--;
                y++;
            }
            
            
            x = i-1;
            y = i;
            
              while(x>=0 and y<n and s[x] == s[y]){
                if(y - x + 1>len){
                    len = y - x+1;
                    left = x;
                    right = y;
                }
                
                x--;
                y++;
            }
            
            
            
            
            
            
        }
        
        
        if(left == right) {
            string ans = "";
            ans+=s.back();
            
            return ans;
        }
        
        for(int i = left;i<=right;i++) ans+=s[i];
        
        
        return ans;
    }
};