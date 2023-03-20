class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int nn = flowerbed.size();
        
        if(nn==1){
            if(n==0) return true;
            if(n==1 and flowerbed[0]==0) return true;
            return false;
        }
        
         
        
        for(int i = 0;i<nn;i++){
            
            if(n==0) break;
            
            if(i==0){
                if(flowerbed[i+1]==0 and flowerbed[0] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
                continue;
            }
            
            if(i==nn-1){
                if(flowerbed[nn-2]==0 and flowerbed[nn-1]==0){
                    flowerbed[nn-1] = 1;
                    n--;
                    break;
                }
                continue;
            }
            
            
            if(flowerbed[i] == 0 and flowerbed[i+1]==0 and flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                //flowerbed[i+1] = 1;
                n--;
            }
        }
        
        for(auto&i:flowerbed) cout<<i<<" ";
        
        
        
        return n==0;
    }
};