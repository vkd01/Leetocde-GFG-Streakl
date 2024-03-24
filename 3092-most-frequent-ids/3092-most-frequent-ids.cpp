typedef long long ll;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& arr, vector<int>& freq) {
        vector<ll> ans;
        
        map<ll,ll> mp;
        maxpq<pair<ll,ll>> pq;
        
        ll n = arr.size();
        
        for(int i = 0;i<n;i++){
            ll ele = arr[i], f = freq[i];
            
            mp[ele]+=f;
            
            pq.push({mp[ele], ele});
            
            while(!pq.empty()){
                ll curr_f = pq.top().first;
                ll curr_mx = pq.top().second;
                
                if(mp[curr_mx] != curr_f){
                    pq.pop();
                }
                else {
                    ans.push_back(curr_f);
                    break;
                }
            }
            
        }
        
        
        
        return ans;
    }
};