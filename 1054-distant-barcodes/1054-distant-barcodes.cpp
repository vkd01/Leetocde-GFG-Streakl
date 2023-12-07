template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& arr) {
        vector<int>ans;
        
        maxpq<pair<int,int>>pq;
        
        
        int n = arr.size();
        
        map<int,int> mp;
        
        for(auto&i:arr) mp[i]++;
        
        
        for(auto&i:mp){
            pq.push({i.second,i.first});
        }
        
        
        while(!pq.empty()){
            pair<int,int> p1 = pq.top();
            pq.pop();
            
            
            bool ok = pq.size()>0;
            
            pair<int,int> p2;
            
            if(ok){
            p2 = pq.top();
            pq.pop();
            }
            
            ans.push_back(p1.second);
            if(ok)ans.push_back(p2.second);
            
            p1.first--;
            if(ok)p2.first--;
            
            if(p1.first>0) pq.push(p1);
            if(ok and p2.first>0) pq.push(p2);
            
            
        }
        
        
        return ans;
    }
};