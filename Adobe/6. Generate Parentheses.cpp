//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#


/*
To form all the sequences of balanced bracket subsequences with n pairs. So there are n opening brackets and n closing brackets. 
So the subsequence will be of length 2*n. There is a simple idea, the i'th character can be '{' if and only if the count of '{' till i'th is less than n and i'th character can be '}' if and only if the count of '{' is greater than the count of '}' till index i. If these two cases are followed then the resulting subsequence will always be balanced. 
So form the recursive function using the above two cases.



Algorithm:  

    Create a recursive function that accepts a string (s), count of opening brackets (o) and count of closing brackets (c) and the value of n.
    if the value of opening bracket and closing bracket is equal to n then print the string and return.
    If the count of opening bracket is greater than count of closing bracket then call the function recursively with the following parameters String s + "}", count of opening bracket o, count of closing bracket c + 1, and n.
    If the count of opening bracket is less than n then call the function recursively with the following parameters String s + "{", count of opening bracket o + 1, count of closing bracket c, and n.


Complexity Analysis: 

    Time Complexity: O(2^n). 
    For every index there can be two options '{' or '}'. So it can be said that the upper bound of time complexity is O(2^n) or it has exponential time complexity.
    Space Complexity: O(n). 
    The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string.
    
*/
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void ans(int n, vector<string>&v, string s, int open, int close)
    {
        if(open>n || close>n || close>open)
        return;
        if(open==close && open==n)
        {
            v.push_back(s);
            return;
        }
        ans(n, v, s+'(', open+1, close);
        ans(n, v, s+')', open, close+1);
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>v;
        string s="";
        ans(n, v, s, 0, 0);
        return v;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends