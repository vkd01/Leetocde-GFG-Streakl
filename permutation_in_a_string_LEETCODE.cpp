class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if(m<n) return false;
        
        vector<int> hash1(26,0), hash2(26,0);
        
        for(auto&i:s1) hash1[i-'a']++;
        
        int left = 0, right = n-1;
        for(int i = left;i<=right;i++) hash2[s2[i]-'a']++;
        
        
        if(hash1==hash2) return true;
        while(right+1<m){
            
            hash2[s2[left]-'a']--;
            left++,right++;
            hash2[s2[right]-'a']++;
            
            // cout<<s2[left]<<" "<<s2[right]<<endl;
            if(hash1==hash2) return true;
        }
        
        
        
        return false;
    }
};