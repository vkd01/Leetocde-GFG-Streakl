class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        
        
        int n = s.size();
        
        for(auto&i:s){
            mp[i] = '$';
        }
        
        map<char,int> used;
        
        for(int i = 0;i<n;i++){
            if(mp[s[i]] == '$' and used.find(t[i]) == used.end() ){
                used[t[i]]++; 
                mp[s[i]] = t[i];
            }
            else if(mp[s[i]] == t[i]) continue;
            else return false;
        }
        
        //for(auto&i:mp) cout<<i.first<<" "<<i.second<<endl;
        
        
        return true;
    }
};