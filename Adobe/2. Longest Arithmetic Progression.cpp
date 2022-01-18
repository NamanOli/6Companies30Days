//https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/#

/*
A simple solution is to one by one consider every pair as first two elements of AP and check for the remaining elements in sorted set. To consider all pairs as first two elements, we need to run a O(n^2) nested loop. Inside the nested loops, we need a third loop which linearly looks for the more elements in Arithmetic Progression (AP). This process takes O(n3) time. 
We can solve this problem in O(n2) time using Dynamic Programming. To get idea of the DP solution, let us first discuss solution of following simpler problem.



Given a sorted set, find if there exist three elements in Arithmetic Progression or not 
Please note that, the answer is true if there are 3 or more elements in AP, otherwise false. 
To find the three elements, we first fix an element as middle element and search for other two (one smaller and one greater). We start from the second element and fix every element as middle element. For an element set[j] to be middle of AP, there must exist elements 'set[i]' and 'set[k]' such that set[i] + set[k] = 2*set[j] where 0 <= i < j and j < k <=n-1. 
How to efficiently find i and k for a given j? We can find i and k in linear time using following simple algorithm. 

    Initialize i as j-1 and k as j+1
    Do following while i >= 0 and k <= n-1
        If set[i] + set[k] is equal to 2*set[j], then we are done.
        If set[i] + set[k] > 2*set[j], then decrement i (do i--).
        Else if set[i] + set[k] < 2*set[j], then increment k (do k++).


Following is the implementation of the above algorithm for the simpler problem.

The above function returns a boolean value. The required output of original problem is Length of the Longest Arithmetic Progression (LLAP) which is an integer value. If the given set has two or more elements, then the value of LLAP is at least 2 (Why?). 
The idea is to create a 2D table L[n][n]. An entry L[i][j] in this table stores LLAP with set[i] and set[j] as first two elements of AP and j > i. The last column of the table is always 2 (Why - see the meaning of L[i][j]). Rest of the table is filled from bottom right to top left. To fill rest of the table, j (second element in AP) is first fixed. i and k are searched for a fixed j. If i and k are found such that i, j, k form an AP, then the value of L[i][j] is set as L[j][k] + 1. Note that the value of L[j][k] must have been filled before as the loop traverses from right to left columns.

We can also reduce space complexity to O(n).
Following is the implementation of the Dynamic Programming algorithm with Space Complexity O(n). 
*/


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n==1 || n==2) return n;
        int dp[n][n];
        int res=2;
        for(int i=0;i<n-1;i++){
            dp[i][n-1]=2;
            dp[i][i+1]=2;
        }
        for(int j=n-2;j>0;j--){
            int i=j-1,k=j+1;
            //dp[j][k]=2;
            while(i>=0 && k<n){
                if(A[i]+A[k]==2*A[j]){
                    dp[i][j]=dp[j][k]+1;
                    //cout<<i<<" "<<j<<"   "<<dp[i][j]<<"  ";
                    res=max(dp[i][j],res);
                    i--;
                    k++;
                }else if(A[i]+A[k]>2*A[j]){
                    dp[i][j]=2;
                    i--;
                }else{
                    k++;
                }
            }
            while(i>=0){
                dp[i][j]=2;
                i--;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends