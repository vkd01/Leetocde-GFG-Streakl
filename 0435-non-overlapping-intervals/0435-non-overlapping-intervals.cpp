class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int ans = 0;
        
        auto comp = [](auto &a, auto &b){
            return a[1]<b[1];
        };
        
        sort(arr.begin(),arr.end(), comp);
        
        int end = -1e9 + 10;
        
        
        for(auto&i:arr){
            if(i[0]<end) ans++;
            else end = i[1];
        }
        
        
        
        return ans;
    }
};