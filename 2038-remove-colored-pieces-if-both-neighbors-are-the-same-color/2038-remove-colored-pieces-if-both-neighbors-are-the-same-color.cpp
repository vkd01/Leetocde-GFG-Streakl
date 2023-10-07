class Solution {
public:
    bool winnerOfGame(string s) {
        
        vector<int> ca, cb;
        
        int temp = 0, n = s.size();
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='A') temp++;
            else{
                ca.push_back(temp);
                temp = 0;
            }
        }
        
        if(temp>0) ca.push_back(temp);
        
        temp = 0;
        
        for(int i = 0;i<n;i++){
            if(s[i] == 'B') temp++;
            else{
                cb.push_back(temp);
                temp = 0;
            }
        }
        
        if(temp>0) cb.push_back(temp);
        
        
        int alice = 0, bob = 0;
        
        for(auto&i:ca) alice+=max(0,i-2);
        
        for(auto&i:cb) bob+=max(0, i-2);
        
        
        
        return alice>bob;
        
        
    }
};














