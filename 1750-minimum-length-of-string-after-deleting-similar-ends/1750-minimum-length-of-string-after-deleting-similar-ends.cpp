class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        
        if(n==1) return 1;
        
        char front = s[0], back =s.back();
        
        while(left<right){
            
           if(s[left] != s[right]) return right - left + 1;
            
            while(left<right and s[left] == back) left++;
            
            while(left<right and s[right] == front) right--;
            
            front = s[left], back = s[right];
            
            
            
        }
        
        if( (left+1<n and s[left] != s[left+1]) and (left-1>=0 and s[left] != s[left-1])) return 1;
        
         
        return 0;
    }
};