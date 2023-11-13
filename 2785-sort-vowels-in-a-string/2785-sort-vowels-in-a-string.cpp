class Solution {
private:
    bool isVowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch == 'o' or ch=='u' 
            or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
    }
public:
    string sortVowels(string s) {
        string v;
        
        for(auto&i:s){
            if(isVowel(i)) v.push_back(i);
        }
        
        sort(v.begin(), v.end());
        
        int ptr = 0;
        
        for(int i = 0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = v[ptr++];
            }
        }
        
        
        return s;
    }
};