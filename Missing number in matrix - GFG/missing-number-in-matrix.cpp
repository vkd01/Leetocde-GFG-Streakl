//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        long long int n = matrix.size();
        long long int r=-1 , c = -1;
        
        for(int i = 0 ; i < n;i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    r= i ; 
                    c = j;
                    break;
                }
            }
            if(r!=-1)
            break;
        }
        long long int tr = 0;
        while(tr==r && tr<n)
        tr++;
        
        long long int sum = 0;
        
        for(int j = 0 ; j < n ;j++)
            sum+=matrix[tr][j];
        
        long long int tmp = sum;
        for(int i = 0 ; i<n;i++)
        sum-=matrix[r][i];
        
        long long int ch = sum;
        //matrix[r][c] = sum;
        
        for(int i = 0 ;i < n ; i++)
        {
            long long int tt = 0;
            for(int j = 0 ;j < n;j++)
              if(i==r && j==c)
                tt+=ch;
              else
                tt+=matrix[i][j];
            if(tt!=tmp)
            return -1;
        }
          
        for(int i = 0 ;i < n ; i++)
        {
            long long int tt = 0;
            for(int j = 0 ;j < n;j++){
              if(i==c && j==r)
                tt+=ch;
              else
                tt+=matrix[j][i];
              }
            if(tt!=tmp)
            {
                 return -1;
            }
           
        }
      
       long long int tt = 0;
        for(int i = 0 ;i < n ; i++)
        if(i==r && i==c)
             tt+=ch;
        else
            tt+=matrix[i][i];
     
        if(tt!=tmp)
        return -1;
        
      
        tt = 0;
        for(int i = 0 ;i < n ; i++)
        if(n-i-1==r && i==c)
             tt+=ch;
        else
            tt+=matrix[n-i-1][i];
    
        if(tt!=tmp)
        return -1;
        
        
        
        return ch<=0 ? -1 : ch;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends