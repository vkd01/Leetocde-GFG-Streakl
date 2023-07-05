class Solution {
const int MOD = 1e9 + 7;
private:
    vector<int>find_prev_smaller(vector<int>&arr){
        stack<pair<int,int>> st;
        int n = arr.size();
        const int inf = 1e9+10;
        vector<int> ans(n);
        
        for(int i = 0;i<n;i++){
            
             while(!st.empty() and st.top().first>=arr[i]) st.pop();
            
            if(st.empty()==true){
                ans[i] = -1;
                st.push({arr[i],i});
                continue;
            }
            
            ans[i] = st.top().second;
            st.push({arr[i],i});
        }
        
        
        
        
        return ans;
    }
public:
    int maxSumMinProduct(vector<int>& arr) {
        long long ans = 0, n= arr.size();
        
        vector<long long> prefix(n,0);
        prefix[0] = arr[0];
        
        for(int i= 1;i<n;i++) prefix[i] = (prefix[i-1] + arr[i]);
        
        
        vector<int> prev_smaller = find_prev_smaller(arr);
  
        
        reverse(arr.begin(),arr.end());
        
        vector<int> next_smaller = find_prev_smaller(arr);
        
        
        reverse(arr.begin(),arr.end());
        for(auto&i:next_smaller) i= n-1 - i;
        reverse(next_smaller.begin(),next_smaller.end());
        
       
        
//         for(int i = 0;i<n;i++){
//             cout<<prev_smaller[i]<<" "<<arr[i]<<" "<<next_smaller[i]<<endl;
//         }
        
        
        for(int i = 0;i<n;i++){
            int x = prev_smaller[i];
            int y = next_smaller[i];
            
            long long sum = prefix[y-1]
                    - (x==-1 ? 0 : prefix[x]);
            
             ans = max((long long)ans, arr[i]*sum);
        }
        
        
        return ans%MOD;
    }
};