class Solution {
private:
    bool isSorted(string &s){
        string temp = s;
        sort(temp.begin(),temp.end());
        return temp == s;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        
        int n = strs.size(),m = strs[0].size();
        
        vector<string> arr;
        
        for(int i = 0;i<m;i++){
             string temp = "";
            for(int j = 0;j<n;j++){       
                  temp+=strs[j][i];
            }
            arr.push_back(temp);
        }
        
        for(auto&i:arr) {
           // cout<<i<<endl;
            if(!isSorted(i)) ans++;
        }
        
        return ans;
    }
};