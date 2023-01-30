class Solution {
public:
    int tribonacci(int n) {
        int ans = 0;
        
        int a = 0, b = 1, c = 1;
        
        if(n==0) return a;
        if(n==1) return b;
        if(n==2) return c;
        
        
        for(int i = 3;i<=n;i++){
            ans = (a+b+c);
            a = b;
            b = c;
            c = ans;
          //  cout<<i<<" "<<a<<" "<<b<<" "<<c<<endl;
        }
        
        
        
        
        return ans;
    }
};