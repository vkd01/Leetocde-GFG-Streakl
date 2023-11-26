class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0) continue;
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        
      //  for(auto&i:matrix) sort(i.begin(), i.end());
        
//         for(auto&i:matrix){
//             for(auto&j:i) cout<<j<<" ";
//             cout<<endl;
//         }
        
        for(int i = 0;i<n;i++){
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            int temp = 1e9+10;
            
            for(int j = 0;j<m;j++){
                if(matrix[i][j]==0) continue;
                
                temp = min(temp, matrix[i][j]);
                
                int area = (j+1)*temp;
                
                ans = max(ans, area);
            }
            
        }
        
        
        
        return ans;
    }
};