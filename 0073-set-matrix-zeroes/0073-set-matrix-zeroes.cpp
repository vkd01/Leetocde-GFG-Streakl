class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        int n = matrix.size(), m = matrix[0].size();
        
        vector<int> rhash(n,0), chash(m,0);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    rhash[i]++;
                    chash[j]++;
                }
            }
        }
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(rhash[i] != 0 or chash[j] != 0) matrix[i][j] = 0;
            }
        }
        
        
        
    }
};