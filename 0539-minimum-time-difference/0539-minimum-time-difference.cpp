class Solution {
public:
    int findMinDifference(vector<string>& arr) {
        int ans = 1e9, n = arr.size();
        
        
        vector<int> temp;
        
        // for(auto&i:arr){
        //     if(i[0]=='0' and i[1] == '0' and i[3]=='0' and i[4] == '0') i = "24:00";
        //     else if(i[0]=='0' and i[1] == '0') {
        //         i[0] = '2';
        //         i[1] = '4';
        //     }
        // }
        
        
        
        for(auto&i:arr){
            int hr = 0, mn = 0;
            
            hr = (i[0] -'0')*10 + (i[1]-'0');
            
            mn = (i[3] - '0')*10 + (i[4]-'0');
            
            int temp_time = hr*60 + mn;
            
            temp.push_back(temp_time);
        }
        
        sort(temp.begin(), temp.end());
        
        
        for(int i = 1;i<temp.size();i++){
            ans = min(ans, temp[i] - temp[i-1]);
        }
        
        int last = (temp[0] + 1440) - temp[n-1]; // 24hours *60 min. = 1440 min.
        ans = min(last,ans);
        
        
        return ans;
        
    }
};