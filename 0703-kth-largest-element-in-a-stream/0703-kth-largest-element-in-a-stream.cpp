class KthLargest {
public:
    priority_queue<int> pq,pq2;
    
    int ind;
    
    KthLargest(int k, vector<int>& nums) {
        for(auto&i:nums) pq.push(-i);
        ind = k;
    }
    
    int add(int val) {
         
        pq.push(-val);
        int x = ind;
        
        
        while(pq.size()>x){
            pq.pop();
        }
        
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */