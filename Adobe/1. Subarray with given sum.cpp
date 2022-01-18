//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    
    // Your code here
    int sum = 0;
    int end;
    int l = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        end = i;
        if(sum > s)
        {
            while(sum > s && l<n)
            {
                sum -= arr[l];
                l++;
            }

        }
        
        if(sum == s)
        {
            cout<<l+1<<" "<<end+1;
            return;
        }
    }
    
    cout<<-1;
    
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        subarraySum(arr, n, s);
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends