class Solution {
private:
    long SUM(int n){
        return (long)n*(n+1)/2;
    }
    
    bool check(long  mid, int maxSum, int n, int index){
         long sum = 0;

            // sum for 0 to index will be counted below
            long reqLeft = mid, haveLeft = index + 1;
            if (index == 0)
            {
                sum += mid;
            }
            else
            {
                if (haveLeft >= reqLeft)
                {
                    sum += SUM(mid);
                    sum += haveLeft - reqLeft;
                }
                else
                {
                    sum += SUM(mid) - SUM(reqLeft - haveLeft);
                }
            }

            // sum for index + 1 to n - 1 will be counted below
            if (index != n - 1)
            {
                long reqRight = reqLeft - 1;
                long haveRight = n - index - 1;

                if (haveRight >= reqRight)
                {
                    sum += SUM(mid - 1);
                    sum += haveRight - reqRight;
                }
                else
                {
                    sum += SUM(mid - 1) - SUM(reqRight - haveRight);
                }
            }

            return sum <= maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        
        
        int low = 1, high = maxSum;
        int ans ;
        
        while(low<=high){
            long mid = low+(high - low)/2;
            
            
            if(check(mid, maxSum, n, index))  {
                ans = mid;
                low = mid+1;
            }
            
            else high = mid-1;
            
        }
        
        return ans;
    }
};