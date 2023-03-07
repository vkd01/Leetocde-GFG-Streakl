class Solution {

private:

    long long binary_s(long long ans, long long totalTrips, vector<int> arr){
        long long trips = 0;
        
        for(auto&i:arr) trips+=(ans/i);
        
        return trips>=totalTrips;
    }
    
public:
    long long minimumTime(vector<int>& arr, int totalTrips) {
        long long ans = 0, time = 0;
        
        long long mn = *min_element(arr.begin(),arr.end());
        
        long long left = 1, right = totalTrips*mn;
        
        
        while(left<right){
            long long mid = left + (right-left)/2;
            
            if(binary_s(mid,totalTrips,arr)) right = mid;
            else left = mid+1;
            
        }
        
        ans = left;
        
        
        return ans;
    }
};