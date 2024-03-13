class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        
        vector<int> f(26,0);
        for(auto&i:s) f[i-'a']++;
        
        for(auto&i:order){
            if(f[i-'a']>0) {
                for(int j = 0;j<f[i-'a'];j++) ans+=i;
            }
        }
        
        for(auto&i:order) f[i-'a']=0;
        for(int i = 0;i<26;i++){
            char ch;
            for(int j = 0;j<f[i];j++) {
                ch = i + 'a';
                ans+=ch;
            }
        }
        
        return ans;
    }
};