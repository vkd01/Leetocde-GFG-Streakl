class FrequencyTracker {
public:
    map<int,int> mp,check;
    
    FrequencyTracker() {
         mp.clear();    
    }
    
    void add(int number) {
         if(check[mp[number]]>0) check[mp[number]]--;
        
        mp[number]++;
      
        check[mp[number]]++;
    }
    
    void deleteOne(int number) {
        
        if(mp[number]>0)
        {
           if(check[mp[number]]>0) check[mp[number]]--;
             int val = mp[number]-1;
            if(val>0) check[val]++;
            mp[number]--;
           
        }
    }
    
    bool hasFrequency(int frequency) {
        for(auto&i:check){
           // cout<<i.first<<" "<<i.second<<endl;
        }
        if(check[frequency]>0) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */