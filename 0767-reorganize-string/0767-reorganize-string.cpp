class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        
        map<char, int> mp;
        for(auto&i:s) mp[i]++;
        int n = s.size();
        int req = (n+1)/2, mx = 0;
        
        for(auto&i:mp) mx = max(mx, i.second);
        
        
       // if(mx>req) return "";
        
        priority_queue<pair<int,char>> pq;
        
        for(auto&i:mp) pq.push({i.second,i.first});
        
        
        while(!pq.empty()){
            pair<int, char> p1, p2;
            
            p1 = pq.top();
            pq.pop();
            if(pq.empty()){
                if(p1.first>1) return "";
                else{
                     ans+=p1.second;
                    return ans;
                }
            }
            p2 = pq.top();
            pq.pop();
            
            ans+=p1.second;
            ans+=p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first>0) pq.push(p1);
            if(p2.first>0) pq.push(p2);
            
            
        }
        
        
        
        
        
        return ans;
    }
};