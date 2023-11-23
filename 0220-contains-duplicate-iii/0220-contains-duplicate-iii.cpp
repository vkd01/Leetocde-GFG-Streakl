class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        vector<pair<int,int>> arr;
        
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            arr.push_back({nums[i], i});
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(arr[j].first - arr[i].first<=valueDiff){
                    if(abs(arr[j].second - arr[i].second)<=indexDiff) return true;
                }
                else break;
            }
        }
        
        return false;
    }
};