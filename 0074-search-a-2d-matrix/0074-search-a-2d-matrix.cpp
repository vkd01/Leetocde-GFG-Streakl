class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(),c = matrix[0].size();
        int i = 0,j = c-1;
        
        while(i<r and j>=0){
            if(matrix[i][j] > target) j--;
            else if(matrix[i][j]<target) i++;
            else return true;
        }
        
        return false;;
    }
};