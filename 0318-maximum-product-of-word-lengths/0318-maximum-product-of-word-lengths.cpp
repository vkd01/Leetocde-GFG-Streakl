class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size(), ans = 0;
        
        vector<int> bits;
        
      
    
        
        for(int i = 0;i<n;i++){
            int n_ = 0;
            
            vector<int> marked(26,0);
            
            for(auto&j:words[i]) {
                if(marked[j-'a'] == 1) continue;
                
                marked[j-'a'] = 1;
                
                n_+=(1<<(j-'a'));
            }
            
            bits.push_back(n_);
            
        }
        
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i==j) continue;
                
                if((bits[i]&bits[j]) == 0){
                    ans = max(ans, (int)words[i].size()*(int)words[j].size());
                }
                
            }
        }
        
         
        
         return ans;
        
        
    }
};