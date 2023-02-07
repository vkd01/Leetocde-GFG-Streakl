class Solution {
    
    void rec(string &s,vector<string> &ans, int open, int close){
        if(open == close and close == 0){
            ans.push_back(s);
            return;
        }
        
        
        if(open>0){
            s.push_back('(');
            rec(s,ans,open-1,close);
            s.pop_back();
        }
        
        if(close>0){
            if(open<close){
                s.push_back(')');
                rec(s,ans,open,close-1);
                s.pop_back();
            }
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        rec(s,ans,n,n);
        
        
        return ans;
    }
};






