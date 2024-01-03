class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        
        
        int prev = 0;
        
        for(int i =  bank.size() - 1;i>=0;i--){
            int one_count = 0;
            
            for(auto&j:bank[i]) one_count+=(j=='1');
            
            ans+=(one_count*prev);
            
            
           // cout<<prev<<" "<<one_count<<endl;
            
            if(one_count != 0)
            prev = one_count;
         
            
        }
        
        
        
        
        return ans;
    }
};