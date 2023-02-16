class Solution {
public:
    vector<int> addToArrayForm(vector<int>& arr, int k) {
        vector<int> ans;
        
        int carry = 0, n = arr.size();
        
        
        for(int i = n-1;i>=0;i--){
            int x = 0;
            if(k>0)
            x = k%10;
            int y = arr[i];
            
          
            int z = (x+y + carry)%10;
          //  cout<<x<<" "<<y<<" "<<carry<<" "<<endl;
            
            ((x+y+carry)>9) ? carry = 1 : carry = 0;
            
            ans.push_back(z);
            k/=10;
            
        }
      //  cout<<carry<<endl;
        while(k>0){
            int x = k%10;
            int y = carry + x;
            int z = y%10;
            (y>9) ? carry = 1 : carry = 0;
            ans.push_back(z);
            k/=10;
        }
        if(carry==1) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};