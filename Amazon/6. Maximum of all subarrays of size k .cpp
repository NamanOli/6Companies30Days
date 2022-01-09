// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
    if(n<k){
        return ans;
    }
    deque<int> Q;
    int i=0;
    
    Q.push_back(arr[i]);
    for(int j=1; j<n;j++){
        if(j-i<k){
            while(!Q.empty() && Q.back()<arr[j]){
                Q.pop_back();
            }
            Q.push_back(arr[j]);
        }
        
        else{
            ans.push_back(Q.front());
            if(arr[i]==Q.front()){
                Q.pop_front();
            }
            while(!Q.empty() && Q.back()<arr[j]){
                Q.pop_back();
            }
            Q.push_back(arr[j]);
            i++;
        }
    }
    ans.push_back(Q.front());
    return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends