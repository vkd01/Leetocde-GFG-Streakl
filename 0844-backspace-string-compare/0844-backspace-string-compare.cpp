class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string a = "", b = "";
        
        for(auto&i:s){
            if(i=='#'){
                if(!st.empty()) st.pop();
                else {
                    
                }
            }
            else st.push(i);
        }
        
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        
        for(auto&i:t){
            if(i=='#'){
                if(!st.empty()) st.pop();
                else{
                    
                }
            }
            else st.push(i);
        }
        
        
        while(!st.empty()){
            b+=st.top();
            st.pop();
        }
        
        return a==b;
        
        
        
    }
};