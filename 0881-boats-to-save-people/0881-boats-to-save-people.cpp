class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        
        sort(people.begin(),people.end());
        
     
        
        int left = 0, right = people.size() - 1;
        
        while(left<=right){
            int two = people[right] + people[left];
            if(left==right){
                right--;
                ans++;
                continue;
            }
            if(two <= limit){
                right--;
                left++;ans++;
            }
            else {  
                right--;
                ans++;
            }
            
        }
        
        
        return ans;
    }
};