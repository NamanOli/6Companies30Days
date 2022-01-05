// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1


/*

1) If length of given array is odd, return false. 

    An odd length array cannot be divided into pairs.

2) Traverse input array and count occurrences of 

    all remainders (use (arr[i] % k)+k)%k for handling the case of negative integers as
     well). 

      freq[((arr[i] % k)+k)%k]++

3) Traverse input array again. 

   a) Find the remainder of the current element.

   b) If remainder divides k into two halves, then

      there must be even occurrences of it as it 

      forms pair with itself only.

   c) If the remainder is 0, then there must be 

      even occurrences.

   d) Else, number of occurrences of current 

      the remainder must be equal to a number of 

      occurrences of "k - current remainder".
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
         map<int,int> m;
        int i,j,p;
        
        for(i=0;i<nums.size();i++) {
            m[nums[i]%k]++;
        }
        bool check=true;
        for(i=0;i<=(k/2);i++) {
            if(i==0 && m[i]%2!=0) {
                check=false;
                break;
            } 
            if(i!=0) {
                if(m[i]!=m[k-i]) {
                    check=false;
                }
            }
        }
        
        return check;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends