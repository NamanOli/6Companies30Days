// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here
  int len=src.length();
  for(int i=0;i<len;i++)
  {
      int count=1;
      while(i<len-1 && src[i]==src[i+1])
      {
          count++;
          i++;
      }
      cout<<src[i]<<count;
  }
}     
 
// Expected Time Complexity: O(N), N = length of given string.
// Expected Auxiliary Space: O(1)