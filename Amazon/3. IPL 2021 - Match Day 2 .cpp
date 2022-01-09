// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#

/*
We will store the maximum in a queue of every subarray . traverese the array and the element in the left smaller than the present max will not be put in the queue while 
    the other elements will be putted.and we will do i++ , before that see if arr[i] present in the queue, if present then popfront. then do j++ and if the back element smaller
    than arr[j] then popback until its not empty or back greater than arr[j] then pushback.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
    vector<int> ans;
    if(arr.size()<k){
        return ans;
    }
    deque<int> Q;
    int i=0;
    
    Q.push_back(arr[i]);
    for(int j=1; j<arr.size();j++){
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

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
