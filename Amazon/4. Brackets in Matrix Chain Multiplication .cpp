/*
https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/

https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     string st;
    
    void printParenthesis(int i, int j, int n, int *bracket, char &name){
    	if (i == j){
    		st += name;
    		name++;
    		return;
    	}
    	st += '(';
    	printParenthesis(i, *((bracket+i*n)+j), n,bracket, name);
    	printParenthesis(*((bracket+i*n)+j) + 1, j,n, bracket, name);
    	st += ')';
    }
    
    string matrixChainOrder(int p[], int n){
        int m[n][n];
    	int bracket[n][n];
    	for (int i = 1; i < n; i++)
    	    m[i][i] = 0;
    	for (int L = 2; L < n; L++){
    		for (int i = 1; i < n-L+1; i++){
    			int j = i+L-1;
    			m[i][j] = INT_MAX;
    			for (int k = i; k <= j-1; k++){
    				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
    				if (q < m[i][j]){
    					m[i][j] = q;
    					bracket[i][j] = k;
    				}
    			}
    		}
    	}
    	char name = 'A';
    	printParenthesis(1, n-1, n, (int *)bracket, name);
    	return st;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends