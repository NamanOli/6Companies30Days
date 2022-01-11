// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/


// https://www.youtube.com/watch?v=CUqylcHwWls


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    int n;
    unordered_map<int, string> keypad;
    public:
    void backtrack(int a[], vector<string> &ans, string &word, int index) {
        if(word.size() == n) {
            return ans.push_back(word);
        }
        
        int num = a[index];
        string s = keypad[num];
        
        for(int i = 0; i < s.size(); i++) {
            word.push_back(s[i]);
            
            backtrack(a, ans, word, index + 1);
            
            word.pop_back();
        }
    }
    
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        keypad = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        n = N;
        
        vector<string> ans;
        string word;
        backtrack(a, ans, word, 0);
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends


