class Solution {
public:
    string largestOddNumber(string s) {
        string ans = "";
        
        int n = s.size();
        
        int ind = n-1;
        
        while(true){
            int x = (s[ind]-'0');

            if(x&1) break;
            ind--;
            
            if(ind==-1) break;
        }
        
       // cout<<ind<<endl;
        
        for(int i = ind;i>=0;i--) ans+=s[i];
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};