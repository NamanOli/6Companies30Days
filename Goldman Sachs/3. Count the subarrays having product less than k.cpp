// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

/*
    Using Sliding Window Technique to calculating the count
    for each iteration multiply a[end] to the product
    if product less than k then finding the lenth of window and add it in result
    else divide the a[start] from product ans start+=1
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long int size=a.size();
        long int start=0;
        long int product=1;
        long int len=0;
        long int res=0;
        for(int end=0;end<size;end++)
        {
            product*=a[end];
            while(start<end && product>=k)
            {
                product=product/a[start];
                start+=1;
            }
            if(product<k)
            {
                len=end-start+1;
                res+=len;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends