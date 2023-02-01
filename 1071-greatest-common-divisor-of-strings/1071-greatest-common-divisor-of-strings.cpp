class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if(s+t != t+s) return "";
        
        int a = s.size();
        int b = t.size();
        int gc = gcd(a,b);
        
        if(a<b) swap(s,t);
        
        return s.substr(0,gc);
    }
};