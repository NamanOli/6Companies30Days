// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#

// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
         // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
       unordered_map<string, int> m;
        for(int i=0;i<n;i++){
            if(m.find(arr[i]) == m.end())
                m.insert({arr[i], 1});
            else m[arr[i]]++;
        }
        
        string ans="";
        int maxi = -1;
        
        for(auto it : m){
            string temp = it.first;
            int cnt = it.second;
            
            if(cnt> maxi){
                maxi = cnt;
                ans = temp;
            }
            else if( cnt == maxi && temp< ans)
                ans = temp;
        }
        vector<string> an;
        an.push_back(ans);
        string x = to_string(maxi);
        an.push_back(x);
        
        return an;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends