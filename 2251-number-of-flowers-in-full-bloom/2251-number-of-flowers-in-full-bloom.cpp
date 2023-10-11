class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        
        vector<int> start, end;
        
        for(auto&i:flowers){
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        
        for(auto&i:people){
             
            auto it = upper_bound(start.begin(), start.end(), i);
            int x = start.size() - (it - start.begin());
            
            it = lower_bound(end.begin(), end.end(),i);
            int y = end.size() - (it - end.begin());
            
            ans.push_back(y - x);
        }
        
        
        
        
        return ans;
    }
};