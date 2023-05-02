class Solution {
public:
    int arraySign(vector<int>& arr) {
        int ans =1;
        for (int i=0;i<arr.size();i++){
            if (arr[i]==0){
                return 0;
            }else if(arr[i]<0){
                ans*=-1;
            }
        }
        return ans;
    }
};