//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool subsetsum(int n, int arr[], int sum){
        // code here 
        bool t[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        t[i][0] = true;
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)
        {
         sum+=arr[i];   
        }
        if(sum%2!=0)
        {
            return false;
        }
        else if(sum%2==0)
        {
            return subsetsum(n,arr,sum/2);
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends