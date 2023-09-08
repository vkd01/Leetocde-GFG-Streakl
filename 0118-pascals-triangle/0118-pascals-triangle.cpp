class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1) return ans;
        ans.push_back({1,1});
        
        int ind = 1;
        
        for(int i  = 3;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1;j<ans[ind].size();j++){
                temp.push_back(ans[ind][j] + ans[ind][j-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            ind++;
        }
        
        return ans;
    }
};