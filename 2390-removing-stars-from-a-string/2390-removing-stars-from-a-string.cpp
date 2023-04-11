class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        
        stack<char> st;
        
        for(auto&i:s){
            if(st.empty()) st.push(i);
            else if((i=='*' and st.top() != '*') or (i!='*' and st.top()=='*')) st.pop();
            else st.push(i);
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};