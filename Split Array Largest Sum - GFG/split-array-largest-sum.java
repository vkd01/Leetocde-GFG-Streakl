//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String St[] = read.readLine().split(" ");
            
            int N = Integer.parseInt(St[0]);
            int K = Integer.parseInt(St[1]);
            
            String S[] = read.readLine().split(" ");
            
            int[] arr = new int[N];
            
            for(int i=0 ; i<N ; i++)
                arr[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.splitArray(arr,N,K));
        }
    }
}
// } Driver Code Ends


class Solution {

    static int splitArray(int[] arr , int N, int K) {

        int sum=0,ans=-1;

        for(int i: arr)

            sum+=i;

        int low=0, high=sum;

        while(low<=high){

            int mid = low+(high-low)/2;

            if(isValid(mid,arr,N,K)){

                ans = mid;

                high = mid-1;

            }    

            else

                low=mid+1;

        }

        return ans;

    }

    

    static boolean isValid(int mid, int[] arr, int N, int K){

        int prevSum=0;

        int partition = 0;

        for(int i=0; i<N; i++){

            if(prevSum+arr[i] <= mid)

                prevSum += arr[i];

            else{

                prevSum=arr[i];

                if(prevSum>mid)    //checking arr[i]

                    return false;

                partition++;    

            }

            if(partition==K)     //it means it divided into K+1 parts

                return false;

        }

        return true;

    }

};