// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#

/*
The problem can be solved by using dynamic programming. 
Let profit[t][i] represent maximum profit using at most t transactions up to 
day i (including day i). Then the relation is:

profit[t][i] = max(profit[t][i-1], max(price[i] – price[j] + profit[t-1][j])) 
          for all j in range [0, i-1] 

profit[t][i] will be maximum of - 

    profit[t][i-1] which represents not doing any transaction on the ith day.
    Maximum profit gained by selling on ith day. In order to sell shares on ith day,
     we need to purchase it on any one of [0, i - 1] days. If we buy shares on jth day 
     and sell it on ith day, max profit will be price[i] – price[j] + profit[t-1][j] where 
    varies from 0 to i-1. Here profit[t-1][j] is best we could have done with one less 
    transaction till jth day.

     time complexity of O(k.n^2)
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N+1];
        for(int i=0;i<=K;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=N;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=K;i++)
        {
            for(int j=1;j<=N;j++)
            {
                int max_so_far = INT_MIN;
                for(int m=0;m<j;m++)
                {
                    max_so_far = max(max_so_far,A[j]-A[m]+dp[i-1][m]);
                }
                dp[i][j]=max(dp[i][j-1],max_so_far);
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends


