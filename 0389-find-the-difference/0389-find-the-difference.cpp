class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> f1(26,0), f2(26,0);
        for(auto&i:s) f1[i-'a']++;
        for(auto&i:t) f2[i-'a']++;
        
        char ans = 'a';
        
        for(int i = 0;i<26;i++){
            if(f1[i] != f2[i]){
                ans+=i;
                break;
            }
        }
        
        
        return ans;
    }
};