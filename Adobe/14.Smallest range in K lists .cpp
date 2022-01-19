// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
     #define p pair<int,pair<int,int>>
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<p,vector<p>,greater<p>>q;
           int mn=INT_MAX,mx=INT_MIN, range=INT_MAX;
            int low=0,high=0;
           for(int i=0;i<k;i++){
            q.push({arr[i][0],{i,0}});
            mn=min(arr[i][0],mn);
            mx=max(arr[i][0],mx);
            
           }
        while(true){
            p temp=q.top();
            q.pop();
            
           int min1=temp.first;
           
            if(range >mx-min1){
                
                mn=min1;
                low=mn;
                high=mx;
                range=mx-mn;
                
            }
          int i=temp.second.first;//array number
          int j=temp.second.second;// index
          
          if(j==n-1)//if fully traversed
          break;
          
          q.push({arr[i][j+1],{i,j+1}});
          
          if(mx <arr[i][j+1])
          {
              mx=arr[i][j+1];
          }
 
        }
        return {low,high};
          
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends