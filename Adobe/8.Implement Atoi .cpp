// https://practice.geeksforgeeks.org/problems/implement-atoi/1/#


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
         //Your code here
        int size = str.size();
        int num = 0;
        int i = 0;
        bool isNegative = false;
        if(str[0] == '-'){
            i=1;
            isNegative = true;
        }
        for(;i<size;i++){
            if(!isdigit(str[i]))
                return -1;
            num = num*10 + (str[i]-'0');
        }
        return isNegative ? (-1)*num : num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends