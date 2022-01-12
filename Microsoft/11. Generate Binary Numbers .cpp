// https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
queue<int> q;
	vector<string> ans;

	q.push(1);
	int val;
	int i=0;
	while(i<N)
	{
	    val = q.front();
	    ans.push_back(to_string(val));
	    val*=10;
	    q.pop();
	    q.push(val+0);
	    q.push(val+1);
	    i++;
	}
	return ans;

}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends