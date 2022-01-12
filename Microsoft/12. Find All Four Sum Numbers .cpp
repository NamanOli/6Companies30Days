// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1,r=n-1;
                while(l<r){
                    int curSum=arr[i]+arr[j]+arr[l]+arr[r];
                    if(curSum==k){
                        ans.push_back({arr[i],arr[j],arr[l],arr[r]});
                        while(l<r && arr[l]==arr[l+1])l++;
                        while(l<r && arr[r]==arr[r-1])r--;
                        l++,r--;
                    }
                    else if(curSum<k)l++;
                    else r--;
                }
                while(j<n-2 && arr[j]==arr[j+1])j++;
            }
            while(i<n-3 && arr[i]==arr[i+1])i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends