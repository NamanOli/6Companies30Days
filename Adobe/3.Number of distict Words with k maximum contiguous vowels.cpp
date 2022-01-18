// https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/

/*
Approach: The idea to solve this problem is based on dynamic programming. Follow the steps below to solve the problem: 

    Let dp[i][j] be the number of ways to make distinct strings of length i where the last j characters of the string are vowels.
    So the states of dynamic programming are:
        If j = 0, then dp[i][j] = (dp[i-1][0] + dp[i-1][1] +......+ dp[i-1][K])*21(represented by the integer variable sum) because the last added character should be a consonant than only the value of j will become 0 irrespective of its value on previous states.
        If i<j then dp[i][j] = 0. Since it is not possible to create a string containing j vowels and has a length less than j.
        If i == j, then dp[i][j] = 5i because the number of characters in the string is equal to the number of vowels, therefore all the characters should be vowels.
        If j<i then dp[i][j] = dp[i-1][j-1]*5 because a string of length i with last j characters vowel can be made only if the last character is the vowel and the string of length i-1 has last j - 1 character as vowels.
    Print the sum of dp[n][0] + dp[n][1] + ...... + dp[n][K] as the answer.


*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
     long long dp[1001][1001], M = 1000000007;
    
    long long solve(int n, int cnt, int k){
        if(n == 0) return 1;
        
       if(dp[n][cnt] != -1) return dp[n][cnt]%M; 
        
        if(cnt == k) return dp[n][cnt] = ((21%M)*(solve(n-1, 0, k))%M)%M;
        
        
        return dp[n][cnt] = (((21%M)*(solve(n-1, 0, k))%M)%M + (5*(solve(n-1, cnt+1, k))%M)%M)%M;
    }
  
    int kvowelwords(int N, int K) {

        memset(dp,-1,sizeof(dp));
        
        return solve(N, 0, K)%M;

    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends