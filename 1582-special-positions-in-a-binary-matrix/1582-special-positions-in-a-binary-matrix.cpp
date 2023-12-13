class Solution {
public:
    int numSpecial(vector<vector<int>>& arr) {
        int ans = 0;
        
        int n = arr.size(), m = arr[0].size();
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] == 1){
                    int x, y;
                    
                    x = i-1;
                    bool ok = true;
                    while(x>=0){
                        ok&=(arr[x][j] == 0);
                        x--;
                    }
                    
                    x = i+1;
                    while(x<n){
                        ok&=(arr[x][j] == 0);
                        x++;
                    }
                    
                    y = j-1;
                    
                    while(y>=0){
                        ok&=(arr[i][y] == 0);
                        y--;
                    }
                    
                    y = j+1;
                    while(y<m){
                        ok&=(arr[i][y] == 0);
                        y++;
                    }
                    
                    ans+=ok;
                }
            }
        }
        
        
        
        return ans;
    }
};