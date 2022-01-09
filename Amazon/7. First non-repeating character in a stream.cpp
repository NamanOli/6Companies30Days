// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int n = A.size();
		    vector<int>f(26, 0);
		    vector<int>last(26, -1);
		    for(int i = 0; i < A.size(); i++){
		        if(last[A[i] - 'a'] == -1)
		            last[A[i] - 'a'] = i;
		    }
		    string ans="";
		    for(int i = 0; i < A.size(); i++){
		        f[A[i] - 'a']++;
		        char ch = '#';
		        int x = A.size() + 1;
		        for(int j = 0; j < 26; j++){
		            if(f[j] == 1 and x > last[j]){
		                ch = char(j + 'a');
		                x = last[j];
		            }
		        }
		        ans += ch;
		    }
		    return ans;
		}

		

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends