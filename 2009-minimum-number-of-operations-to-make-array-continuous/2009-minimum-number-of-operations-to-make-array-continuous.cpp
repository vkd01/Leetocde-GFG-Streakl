class Solution {
public:
    int minOperations(vector<int>& arr) {
        int ans = 1e9 + 10;
        
        int n = arr.size();
        
        map<int,int> mp;
        
        for(auto&i:arr) mp[i]++;

        vector<int> v;
  
            for(auto&i:mp){
                if(i.second>0){
                    v.push_back(i.first);
                    i.second--;
                }
            }       
   
     
        
        for(int i = 0;i<v.size();i++){
            
            int left = v[i];
            
            int right = n + left -1;
            
            auto it = upper_bound(v.begin(),v.end(), right);
            int remove = it - v.begin();
            int temp = n - (remove  - i);
            
            ans = min(ans, temp);
 
            
        }
        
        
        
        
        
        return ans;
    }
};