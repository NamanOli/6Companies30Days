// https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/
// https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1#


// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int n , int m , int k) {
    // n - k + 1 is number of positions
    // before we reach beginning of circle
    // If m is less than this value, then
    // we can simply return (m-1)th position
    if (m <= n - k + 1)
        return m + k - 1;
 
    // Let us compute remaining items before
    // we reach beginning.
    m = m - (n - k + 1);
 
    // We compute m % n to skip all complete
    // rounds. If we reach end, we return n
    // else we return m % n
    return (m % n == 0) ? n : (m % n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends