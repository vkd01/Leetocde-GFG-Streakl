class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n>0){
            n--;
            char ch = n%26 + 'A';
            ans = (ch + ans);
            n/=26;
        }
        
        return ans;
    }
};