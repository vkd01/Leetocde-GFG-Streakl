class Solution {
private:
    bool allDone(vector<int>&arr){
        for(auto&i:arr){
            if(i>0) return false;
        }
        
        return true;
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        
        map<char, int> mp;
        
        for(auto&_:tasks){
            mp[_]++;
        }
        
        
        int time = 0;
        
//         while(!check())
        
        vector<int> temp;
        
        for(auto&i:mp) temp.push_back(i.second);
        
        sort(temp.begin(), temp.end(), greater<int>());
        
       
        
        while(!allDone(temp)){
            
            int count = 0;
            
            bool first = false, n_ = false;
            
            for(int i = 0;i<temp.size();i++){
      
                if(temp[i]>0) count++;
                if(temp[i]>0) temp[i]--;
                
                if(count==n+1){
                    ans+=(count);
                    sort(temp.begin(), temp.end(), greater<int>());
                    n_ = true;
                    break;
                }
                
                
            }
            
            if(n_) continue;
            
           cout<<"Debug "<<count<<" "<<ans<<endl;
            
            for(auto&i:temp) cout<<i<<" ";
            cout<<endl;
            
            ans+=(count);
            
            if(allDone(temp) == false)
            ans+=max(0, n - count+1);
            
            
        }
        
        
        
        return ans;
    }
};