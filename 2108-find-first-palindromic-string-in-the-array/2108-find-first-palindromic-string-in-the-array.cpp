class Solution {
private:
    bool isPal(string &s){
        int left = 0, right = s.size() - 1;
        
        while(left<=right){
            if(s[left] != s[right]){
                return false;
                
            }
            left++;
            right--;
        }
        
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto&i:words){
            if(isPal(i)){
                return i;
            }
        }
        
        return "";
    }
};