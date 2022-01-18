// https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int len=N.length();
        
        if(len==1 || len==2){
            return "-1";
        }
        string half= N.substr(0,len/2);
        string ans="-1";
        
        if(next_permutation(half.begin(),half.end())){
            ans=half;
            if(len%2==1){
                ans=ans+N[len/2];
            }
            reverse(half.begin(),half.end());
            ans=ans+half;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends