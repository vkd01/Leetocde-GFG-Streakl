
class Solution {
    
private:
    
    void fairy(priority_queue<int, vector<int>, greater<int> > &pq1, priority_queue<int, vector<int>, greater<int> > &pq2, 
               int &cnt, int &k,vector<int> &costs, int &j, long long &res,int &ptr){
        
        
        while(k--){
            if(pq1.size()==0){
                res+=pq2.top();
                pq2.pop();
                if(ptr<=j){
                   pq2.push(costs[j]);
                    j--;
                } 
                
            }
            else if(pq2.size()==0){
                res+=pq1.top();
                pq1.pop();
                if(ptr<=j){
                    pq1.push(costs[ptr]);
                    ptr++;
                } 
            }
            else if(pq1.top()<=pq2.top()){
                res+=pq1.top();
                pq1.pop();
                if(ptr<=j){
                    pq1.push(costs[ptr]);
                    ptr++;
                }
            }
            else{
                res+=pq2.top();
                pq2.pop();
                if(ptr<=j){
                 pq2.push(costs[j]);
                    j--;
                } 
                
                
            }
        }
    }
    
    
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res=0;
        priority_queue<int, vector<int>, greater<int> > pq1;
        priority_queue<int, vector<int>, greater<int> > pq2;
        int ptr=0;
        while(ptr<candidates){
            pq1.push(costs[ptr]);
            ptr++;
        }
        int cnt = 0;
        int j= costs.size()-1;
        if(candidates > costs.size()- candidates){
            candidates= costs.size()- candidates;
        }
    
        while(cnt<candidates){
            pq2.push(costs[j]);
            cnt++;
            j--;
        }
        
        fairy(pq1,pq2,cnt,k, costs,j,res,ptr);

        return res;
    }
};