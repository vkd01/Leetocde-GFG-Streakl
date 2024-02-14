class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        
        for(auto&i:nums) {
            if(i<0) neg.push_back(i);
            else pos.push_back(i);
        }
        
        vector<int> ans;
        
        int gate = 0, ptr1 =0, ptr2 = 0;
        
        for(int i = 0;i<(int)nums.size();i++){
            if(gate == 0){
                ans.push_back(pos[ptr1++]);
            }
            else ans.push_back(neg[ptr2++]);
            
            gate^=1;
        }
        
        return ans;
    }
};