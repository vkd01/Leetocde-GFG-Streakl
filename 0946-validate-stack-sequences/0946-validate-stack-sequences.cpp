class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        
        
        int n = pushed.size();
        
        
       int i = 0, j =0;
        
        while(i<n and j<n){
            if(st.empty()) {
                st.push(pushed[i]);
                i++;
            }
            else if(st.top()==popped[j]){
                st.pop();
                j++;
            }
            
            else {
                st.push(pushed[i]);
                i++;
            }
        }
        
        cout<<i<<' '<<j<<endl;
        
        while(i<n) {
            st.push(pushed[i]);
            i++;
        }
        while(j<n){
            if(st.top()==popped[j]){
                st.pop();
            j++;
            }
            
            else return false;
            
        }
        
        
        
        
        
        
        
        return st.size() == 0;
    }
};