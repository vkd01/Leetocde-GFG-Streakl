class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        
        int n = arr.size();
        
        stack<int> st;
        
        for(auto&i:arr){
            if(st.empty()){
                st.push(i);
                continue;
            }
            
            bool equal = false;
            
            int curr = i;
            
            while(!st.empty() and curr < 0 and st.top()>0){
                int x = st.top();
                st.pop();
                bool neg = (curr<0);
                if(abs(x)!=abs(curr)){
                    if(abs(x)>abs(curr)){
                        if(neg) curr = x;
                        else curr = -x;
                    }
                    else {
                        
                    }
                    
                // curr = max(x,curr);
                }
                    
                else {
                    equal = true;
                    break;
                }
            }
            if(!equal)
             st.push(curr);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        
        
        return ans;
    }
};