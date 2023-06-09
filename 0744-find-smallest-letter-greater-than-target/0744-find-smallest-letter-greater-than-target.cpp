class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        
        
        int diff = 1000;
        
        for(auto&i:letters){
            int curr = (i-'0') - (target - '0');
            
            if(curr>0 and diff>curr){
                diff = curr;
                ans = i;
            }
        }
        
        
        return ans;
    }
};