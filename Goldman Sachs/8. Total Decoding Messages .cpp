// https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#


// Iterative

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string s)
		{
		    long long int mod = 1000000007 ;
		    if(s.size() < 1 ) return 0 ;
		    if(s[0]=='0') return 0 ;
		    if(s.size()==1)  return 1 ;
		    int l1 = 1 ;
		    int l2 = 1 ;
		    for(long long int i=1 ; i<s.size() ;i++)
		    {
		        int d1 = s[i]-'0' ;
		        int d2 = (s[i-1]-'0')*10 + d1 ;
		        int val = 0 ;
		        
		        if(d1>=1) 
		          val = (val+l2)%mod ;
		        
		        if(d2>9 && d2<=26)
		          val = (val+l1)%mod ;
		        
		        l1 = l2 ;
		        l2 = val ;
		    }
		  
		  return l2%mod ;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends


// Recursive 

/*
We initialize the total count of decodings as 0. We recur for two subproblems. 
    1) If the last digit is non-zero, recur for the remaining (n-1) digits and add the result 
    to the total count. 
    2) If the last two digits form a valid character (or smaller than 27), recur for remaining
    (n-2) digits and add the result to the total count.
*/


#include <bits/stdc++.h>
using namespace std;

// recuring function to find
// ways in how many ways a
// string can be decoded of length
// greater than 0 and starting with
// digit 1 and greater.
int countDecoding(char* digits, int n)
{
    // base cases
    if (n == 0 || n == 1)
        return 1;
    if (digits[0] == '0')
        return 0;

    // for base condition "01123" should return 0
    // Initialize count
    int count = 0; 

    // If the last digit is not 0,
    // then last digit must add 
    // to the number of words
    if (digits[n - 1] > '0')
        count = countDecoding(digits, n - 1);

    // If the last two digits form a number smaller
    // than or equal to 26, then consider
    // last two digits and recur
    if (digits[n - 2] == '1'
        || (digits[n - 2] == '2' 
        && digits[n - 1] < '7'))
        count += countDecoding(digits, n - 2);

    return count;
}

// Given a digit sequence of length n,
// returns count of possible decodings by
// replacing 1 with A, 2 with B, ... 26 with Z
int countWays(char* digits, int n)
{
    if (n == 0 || (n == 1 && digits[0] == '0'))
        return 0;
    return countDecoding(digits, n);
}

// Driver code
int main()
{
    char digits[] = "1234";
    int n = strlen(digits);
    cout << "Count is " << countWays(digits, n);
    return 0;
}


// DP 


// A Dynamic Programming based C++ 
// implementation to count decodings
#include <bits/stdc++.h>
using namespace std;

// A Dynamic Programming based function 
// to count decodings
int countDecodingDP(char *digits, int n)
{
    // A table to store results of subproblems
    int count[n+1]; 
    count[0] = 1;
    count[1] = 1;
    //for base condition "01123" should return 0 
    if(digits[0]=='0')  
         return 0;
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;

        // If the last digit is not 0, 
        // then last digit must add to the number of words
        if (digits[i-1] > '0')
            count[i] = count[i-1];

        // If second last digit is smaller 
        // than 2 and last digit is smaller than 7,
        // then last two digits form a valid character 
        if (digits[i-2] == '1' || 
              (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }
    return count[n];
}

// Driver program to test above function
int main()
{
    char digits[] = "1234";
    int n = strlen(digits);
    cout << "Count is " << countDecodingDP(digits, n);
    return 0;
}



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int mod = 1000000007;
		int CountWays(string str){
		    int n = str.size();
		    int dp[n+1];
		    if (str[0]=='0'){
		        return 0;
		    }
		    memset(dp,0,sizeof dp);
		    dp[0] = 1;
		    dp[1]  =1;
		    for (int i =2; i<=n; i++){
		        if (str[i-1]>'0'){
		            dp[i]=(dp[i]%mod+dp[i-1]%mod)%mod;
		        }
		        if ((str[i-2]=='1')||(str[i-2]=='2'&&str[i-1]<'7')){
		            dp[i]=(dp[i]%mod+dp[i-2]%mod)%mod;
		        }
		    }
		    return dp[n]%mod;
		    
		   
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
