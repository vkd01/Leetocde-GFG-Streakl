class Solution {
public:
    bool validPalindrome(string s) {
        
        int left = 0, right = s.size()-1;
        
        int count = 0;
        
        int x = -1, y =-1;
        
        bool good = true;
        
        while(left<right){
            if(s[left] != s[right]){
                x = left, y = right;
                good = false;
                break;
            }
            left++;
            right--;
        }
        
        if(good) return true;
        
   //     cout<<x<<" "<<y<<endl;
        
        left = x, right = y;
        
        left++;
        
        bool ok1 = true , ok2 = true;
        
        while(left<right){
            if(s[left] != s[right]){
                ok1 = false;
            }
            left++;
            right--;
        }
        
        left = x, right = y;
        
        right--;
        
        while(left<right){
            if(s[left] != s[right]){
                ok2 = false;
            }
            left++;
            right--;
        }
        
        
        
        return ok1 or ok2; 
        
    }
};