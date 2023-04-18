class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        
        int i = 0;
        for( i = 0;i<min(word1.size(),word2.size());i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        
         if(word1.size()>word2.size()){
             for(int j = i;j<max(word1.size(),word2.size());j++) ans+=word1[j];
         }
        else {
             for(int j = i;j<max(word1.size(),word2.size());j++) ans+=word2[j];
        }
        
        
        return ans;
    }
};