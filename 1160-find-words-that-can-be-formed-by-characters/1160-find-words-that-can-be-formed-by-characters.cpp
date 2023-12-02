class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        map<char, int> mp, temp;
        
        for(auto&i:chars) mp[i]++;
        
        int ans = 0;
        
        for(auto&s:words){
            temp = mp;
             
            bool ok = true;
            
             for(auto&i:s){
                 if(temp[i]==0){
                     ok = false;
                      break;
                 }
                 
                 temp[i]--;
             }
            if(ok) ans+=s.size();
        }
        
        return ans;
    }
};