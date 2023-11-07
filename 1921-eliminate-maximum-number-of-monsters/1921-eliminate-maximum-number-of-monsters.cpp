 template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
 template<typename T> using maxpq = priority_queue<T>;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 0, n = dist.size();
        
        
        vector<float> time;
        
        
        for(int i = 0;i<n;i++){
            float d = dist[i];
            float s = speed[i];
            float t = d/s;
            time.push_back(t);
        }
        
        
        
        minpq<float> pq;
        
        for(auto&i:time) pq.push(i);
        
        float curr = 0.00000;
        
        
        while(pq.size()>0){
            
            float x = pq.top();
            
        //    cout<<x<<endl;
            
            pq.pop();
            x-=curr;
            
            if(x<=0){
                break;
            }
            
            ans++;
            curr++;
            
        }
        

        
        
        return ans;
    }
};