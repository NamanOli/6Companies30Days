// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#
// https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int len=S.length();
        string res;
        stack<int>st;
        for(int i=0;i<=len;i++)
        {
            st.push(i+1);
            if(S[i]=='I'||i==len)
            {
                while(!st.empty())
                {
                    res+=to_string(st.top());
                    res+="";
                    st.pop();
                }
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends