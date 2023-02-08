class Solution {
private:
    
   
        

//     void putQUEEN(vector<string> &board, int i, int j){
//         board[i][j] = 'Q';
//     }
//     void removeQUEEN(vector<string> &board,int i, int j){
//         board[i][j] = '.';
//     }
    
    
    
    
private:
     bool isValid(vector<string> &board, int row, int col){
        // CHECKING FOR THE COLOUMN .....
        for(int i = row;i>=0;i--) if(board[i][col]=='Q') return false;
        
        //CHECKING FOR LEFT DIAGONAL ....
        
        for(int i = row, j = col; j>=0 and i>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //CHECKING FOR RIGHT DIAGONAL....
        
        for(int i = row, j = col; i>=0 and j<board.size();i--,j++){
            if(board[i][j]=='Q') return false;
        }
        
       
        
        
        return true;
    }
    
    
    void putQUEEN(vector<string> &board, int i , int j){
        board[i][j] = 'Q';
    }
    void removeQUEEN(vector<string>&board, int i, int j){
        board[i][j] = '.';
    }
    
void dfs(vector<vector<string>> &ans,vector<string>&board, int row){
        if(row==board.size()) {
            ans.push_back(board);
            return;
        }
        
        for(int i = 0;i<board.size();i++){
            if(isValid(board, row, i)) {
                putQUEEN(board,row,i);
                
                dfs(ans,board,row+1);
                
                removeQUEEN(board, row , i);
                
            }
        } 
    }
    
    
 
    
    
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        vector<string> board(n,string(n,'.'));
        
        dfs(ans,board,0);
        
        
        return ans;
    }
};