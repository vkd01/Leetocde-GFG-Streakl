class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        
        
        map<char, int> mp;
        
        for(auto&i:s) mp[i]++;
        
        priority_queue<pair<int, char>> pq;
        
        
        for(auto&i:mp) pq.push({i.second, i.first});
        
        
        
        while(!pq.empty()){
            int times = pq.top().first;
            char ch = pq.top().second;
            
            pq.pop();
            
            for(int i = 0;i<times;i++) ans+=ch;
        }
        
        
        
        
        return ans;
    }
};