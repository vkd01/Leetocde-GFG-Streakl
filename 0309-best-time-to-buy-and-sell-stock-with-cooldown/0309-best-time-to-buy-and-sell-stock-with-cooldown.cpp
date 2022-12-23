class Solution {
public:
    map<vector<int>, int>mp;// dp.
    int util(vector<int>& arr, int idx, int buy, int isCoolDown){
        if(idx==arr.size()){
            return 0;
        }
        if(mp.find({idx, buy, isCoolDown})!=mp.end())return mp[{idx, buy, isCoolDown}];
        if(buy==1){//buying phase
            if(isCoolDown==0){//0=>not a cooling day.
                return mp[{idx, buy, isCoolDown}]=max(util(arr, idx+1, 0, 0)-arr[idx], util(arr, idx+1, 1,0));
            }else{//cooling day.
                return mp[{idx, buy, isCoolDown}]=util(arr, idx+1, buy, 0);
            }
        }else{//selling phase.
            return mp[{idx, buy, isCoolDown}]=max(util(arr, idx+1, 1, 1)+arr[idx], util(arr, idx+1, 0, 0));
        }
    }
    int maxProfit(vector<int>& prices) {
        return util(prices, 0, 1, 0);
    }
};