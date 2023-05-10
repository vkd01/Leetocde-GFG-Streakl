class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        
        int dx[4] = {0,1,2,3};
        int dir = dx[0];
        
        int top = 0,bottom = n-1,left = 0,right = n-1,fill=1;
        
        while(top<=bottom and left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++) {
                    matrix[top][i] = fill;
                    fill++;
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++) {
                    matrix[i][right] = fill;
                    fill++;
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right;i>=left;i--){
                    matrix[bottom][i] = fill;
                    fill++;
                }
                bottom--;
            }
            else if(dir == 3){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left] = fill;
                    fill++;
                }
                left++;
            }
            
           dir = dx[(dir+1)%4];
        }
        return matrix;
    }
};