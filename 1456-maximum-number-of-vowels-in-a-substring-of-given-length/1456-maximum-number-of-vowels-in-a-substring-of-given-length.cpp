class Solution {
private:
    bool isVowel(char ch){
        return ch=='a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0, n = s.size();
        
        int left = 0, right = 0;
        
        for(int i = 0;i<k;i++) {
            if(isVowel(s[i])) ans++;
            right++;
        }
     
        right--;
        int temp = ans;
        
        while(right<n){
            if(isVowel(s[left])) temp--;
            left++, right++;
            if(isVowel(s[right])) temp++;
            
            ans = max(ans,temp);
        }
        
        return ans;
        
    }
};