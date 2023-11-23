class Solution {
public:
    int numberOfBeams(vector<string>& s) {
        int ans = 0;
        
        int prev = 0;
        
        int n = s.size(), m = s[0].size();
        
        for(int i = n-1;i>=0;i--){
            
            int lazers = 0;
            
            for(int j = 0;j<m;j++) lazers+=(s[i][j]=='1');
            
           // cout<<lazers<<" "<<prev<<endl;
            
            ans+=(lazers*prev);
            
            if(lazers != 0)
            prev = lazers;
            
            
            
        }
        
        
        return ans;
    }
};