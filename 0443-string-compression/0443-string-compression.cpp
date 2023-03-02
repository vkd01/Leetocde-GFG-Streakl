class Solution {
private:
    int len(int n){
        int ans = 0;
        while(n>0) {
            ans++;
            n/=10;
        }
        return ans;
    }
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        if(n==1) return 1;
        
        int ptr1 = 0;
        string ans = "";
        while(ptr1<n-1){
            ans+=chars[ptr1];
            string temp = "$";
    
            while(ptr1<n-1 and chars[ptr1]==chars[ptr1+1]) temp+='$',ptr1++;
               
            if(temp.size()!=1) ans+=to_string(temp.size());
      
            ptr1++;
        }
        if(chars[n-1]!=chars[n-2]) ans+= chars[n-1];
        
        for(int i=0;i<ans.size();i++)  chars[i] = ans[i];
        
        return ans.size();
        
    }
};