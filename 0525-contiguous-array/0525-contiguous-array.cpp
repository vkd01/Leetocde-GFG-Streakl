class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        
        for(auto&i:arr) {
            if(i==0) i = -1;
        }
        
        map<int,int> mp;
        mp[0] = -1;
        
        int prefix = 0, ans = 0, n = arr.size();
        
        for(int i = 0;i<n;i++){
            prefix+=arr[i];
            
            if(mp.find(prefix) != mp.end()){
                ans = max(ans, i - mp[prefix]);
            }
            else mp[prefix] = i;
        }
        
        return ans;
    }
};