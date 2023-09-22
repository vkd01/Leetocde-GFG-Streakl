class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        swap(s,t);
        
        int i = 0, j = 0;
        
        while(i<s.size() and j<t.size()){
           if(s[i] == t[j]){
               j++;
           }
            i++;
        }
        
     //   cout<<i<<" "<<j<<endl;
        
        return j == t.size();
    }
};