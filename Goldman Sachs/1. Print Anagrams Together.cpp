// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#


/*
  Create a map with the sorted string as key and strings as value
  Traverse the vector and store the strings in the map according to the strings after sorting
  // Print the solutions
*/


// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>ans; // storing the result
        map<string,vector<string>>mp; // Storing the strings which are same after sorting
        for(auto x:string_list)
        {
            string tmp=x; 
            sort(tmp.begin(),tmp.end()); // sorting the string
            mp[tmp].push_back(x);
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends