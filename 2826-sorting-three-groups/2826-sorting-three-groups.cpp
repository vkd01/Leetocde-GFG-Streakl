class Solution {
    
int fans(vector<int>&arr, int x,int y){
    
        int ans = 1e9+10, n = arr.size();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int count = 0;
                for(int k=0;k<i;k++) count+=(arr[k] != x);
                for(int k = i;k<n;k++) count+=(arr[k] !=y);
                ans = min(ans, count);
            }
        }
    return ans;
    }
public:
    int minimumOperations(vector<int>& arr) {
        int ans = 1e9+10, n = arr.size();
        
        if(n==1){
            return 0;
        }
        if(n==2){
             if(arr[0]>arr[1]) return 1;
            else return 0;
        }
        
        set<int> st;
        for(auto&i:arr) st.insert(i);
        
        if(st.size() == 1) return 0;
        
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                
                int x = 0,y = 0,z = 0;
                
                for(int k = 0;k<i;k++) x+=(arr[k]!=1);
                
                for(int k = i;k<j;k++) y+=(arr[k]!=2);
                
                for(int k = j;k<n;k++) z+=(arr[k] != 3);
                
                ans = min(ans, x+y+z);
            }
        }
        
        int x1 = fans(arr, 1,2);
        int x2 = fans(arr, 2,3);
        int x3 = fans(arr, 1,1);
        int x4 = fans(arr, 2,2);
        int x5 = fans(arr, 3,3);
        
        ans = min({ans, x1, x2,x3,x4,x5});
        
        
        
        
        
        return ans;
    }
};