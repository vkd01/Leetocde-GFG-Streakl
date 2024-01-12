class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or
            ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
    }
public:
    bool halvesAreAlike(string s) {
        
        
        int count1 = 0, count2 = 0, n = s.size();
        
        
        for(int i = 0;i<n/2;i++){
            count1+=(isVowel(s[i]));
        }
        
        for(int i = n/2;i<n;i++){
            count2+=(isVowel(s[i]));
        }
        
        return count1 == count2;
        
    }
};