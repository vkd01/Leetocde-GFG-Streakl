class Solution {
public:
    string maximumOddBinaryNumber(string s) {
      
        
        int set_bits = 0;
        for(auto&i:s) set_bits+=(i=='1');
        
        string ans(s.size(),'0');
        
        ans.back() = '1';
        
        set_bits--;
        
        for(int i = 0;i<set_bits;i++){
            ans[i] = '1';
        }
        
        
        return ans;
    }
};