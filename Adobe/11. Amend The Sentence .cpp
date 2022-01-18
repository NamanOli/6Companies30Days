// https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans;
        int i=0;
        int n = s.length();
        bool space = false;
        while(i<n){
            if(isupper(s[i])){
                if(space){
                    ans += ' ';
                }
                ans += tolower(s[i]);
            }
            else{
                ans += s[i];
            }
            space = true;
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends