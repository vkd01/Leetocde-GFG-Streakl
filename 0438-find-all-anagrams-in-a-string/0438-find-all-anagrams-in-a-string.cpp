class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        
        if(m>n) return ans;
        
        int left = 0, right = m-1;
        
        vector<int> hash1(26,0), hash2(26,0);
        
        for(auto&i:p) hash2[i-'a']++;
        for(int i = left;i<=right;i++) hash1[s[i]-'a']++;
        
        if(hash1==hash2) ans.push_back(0);
        
        while(right+1<n){
            hash1[s[left]-'a']--;
            left++,right++;
            hash1[s[right]-'a']++;
            
            if(hash1==hash2) ans.push_back(left);
        }
        
        
        
        
        
        
        return ans;
    }
};