class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int winner = arr[0];
        
        if(k>arr.size()){
            return *max_element(arr.begin(),arr.end());
        }
        
        
        deque<int> dq;
        
        for(auto&i:arr) dq.push_back(i);
        
        
        map<int,int> mp;
        
        while(true){
            int x = dq.front();
            dq.pop_front();
            int y = dq.front();
            dq.pop_front();
            
            
            if(x>y) swap(x,y);
            
            mp[y]++;
            
            if(mp[y]==k) return y;
            
            dq.push_front(y);
            
            dq.push_back(x);
            
        }
        
        return dq.front();
        
    }
};