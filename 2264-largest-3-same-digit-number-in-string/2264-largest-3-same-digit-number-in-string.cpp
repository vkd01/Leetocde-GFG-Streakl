class Solution {
public:
    string largestGoodInteger(string s) {
        string ans = "";
        int n = s.size();
        
        bool found = false;
        
        int curr = -1;
        
        for(int i = 0;i<n;i++){
            for(int j = i;j<min(i+3,n);j++){
                
                if(!(s[j] == s[j+1] and s[j+1] == s[j+2])) continue;
                
                string temp = "";
                temp+=s[j];
                temp+=s[j+1];
                temp+=s[j+2];
                
                int num = stoi(temp);
                
                if(num>curr){
                    curr = num;
                    ans = temp;
                }
                
            }
        }
        
        // if(curr==-1){
        //     for(int i = 0;i<n;i++){
        //         for(int j = i;i<min(i+3,n);j++){
        //             if(s[j]=='0' and s[j] == s[j+1] and s[j+1] == s[j+2]){
        //                 return "000";
        //             }
        //         }
        //     }
        // }
        
        return ans;
    }
};