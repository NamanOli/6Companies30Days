// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s="";
        
        
        while(n!=0){
            n--;
            int r=n%26;
            char ch= 'A'+r;
            s = ch +s;
            n=n/26;
            
        }
        
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends