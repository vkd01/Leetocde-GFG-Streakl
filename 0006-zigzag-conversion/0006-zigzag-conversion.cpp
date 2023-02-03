class Solution {
public:
    string convert(string s, int numRows) {
      
        string v[numRows];
        
        if(numRows==1){
            return s;
        }
        
        int row = 0;
        bool diagonal ;
        for(int i = 0;i<s.size();i++){
            v[row].push_back(s[i]);
            if(row==numRows - 1) diagonal = true;
            else if (row==0) diagonal = false;
            
            
            if(diagonal) row--;
            else row++;
        }
        
        string ans = "";
        for(int i = 0;i<numRows;i++)
        ans+=v[i];
        
        
        return ans;
    }
};