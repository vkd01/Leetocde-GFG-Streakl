class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        
        for(auto&i:stones) pq.push(i);
        
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x==y) continue;
            else pq.push(abs(x-y));
        }
        
        if(pq.size()==0) return 0;
        
        return pq.top();
    }
};