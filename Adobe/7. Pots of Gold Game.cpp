// https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int helper(int s,int e,vector<int> &A,vector<vector<int>> &dp){
        //if(s>e) return 0;
        if(s==e) return A[e];
        if(s+1==e) return max(A[s],A[e]);
        if(dp[s][e]!=-1) return dp[s][e];
        int l=A[s]+min(helper(s+2,e,A,dp),helper(s+1,e-1,A,dp));
        int r=A[e]+min(helper(s+1,e-1,A,dp),helper(s,e-2,A,dp));
        return dp[s][e]=max(l,r);
    }
    
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n,vector<int>(n,-1));
	    return helper(0,n-1,A,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends