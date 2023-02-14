class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        
        int as = a.size(), bs = b.size();
        
        int carry = 0;
        int ptr1 = as-1, ptr2 = bs-1;
        for(int i = min(as,bs)-1; i>=0;i--){
            int x = a[ptr1] - '0';
            int y = b[ptr2] - '0';
            if(x+y==2) {
                if(carry>0) {
                    ans+='1';
                }
                else ans+='0';
                carry = 1;
            }
            else if(x+y==1) {
                if(carry>0){
                    ans+='0';
                    carry = 1;
                }
                else ans+='1';

            }
            else {
                if(carry>0){
                    ans+='1';
                    carry--;
                }
                else ans+='0';
            }
            ptr1--,ptr2--;
          // cout<<ans<<endl;
        }
        
        
         if(as>bs){
             for(int i = abs(as-bs)-1;i>=0;i--){
              //   cout<<i<<endl;
                  if(carry>0){
                      if(carry+a[i]-'0' ==2){
                          carry = 1;
                          ans+='0';
                      }
                      else if(carry+a[i]-'0'==1) {
                          ans+='1';
                          carry = 0;
                      }
                  }
                 else ans+=a[i];
             }
         }
       else if(as<bs){
             for(int i = abs(as-bs)-1;i>=0;i--){
                  if(carry>0){
                      if(carry+b[i]-'0' ==2){
                          carry = 1;
                          ans+='0';
                      }
                      else if(carry+b[i]-'0'==1) {
                          ans+='1';
                          carry = 0;
                      }
                  }
                 else ans+=b[i];
             }
         }
        if(carry==1) ans+='1';
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};