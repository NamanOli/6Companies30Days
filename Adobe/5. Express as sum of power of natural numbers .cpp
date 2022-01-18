//https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#

//https://www.geeksforgeeks.org/find-ways-integer-can-expressed-sum-n-th-power-unique-natural-numbers/


// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long numOfWays(int n, int x)
    {
        // Here, dp[i] represents number of ways to represent i
        long long dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        // Always 1 way to represent 0 or 1
        // as sum of powers of natural numbers
        dp[0] = dp[1] = 1;
        
        // For n == 10 and x == 2, we will only try till 3^2
        // else, the sum will exceed n
        int maxLimit = pow(n, 1.0/x);

        for(int i = 2; i <= maxLimit; i++){
            int curr = pow(i, x);
            
            // Same as "include" condition in recursive code
            // and since, we are running a loop from i to maxLimit
            // the "exclude" condition is also handled.
            for(int j = n; j >= curr; j--){
                dp[j] += dp[j-curr];
            }
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends