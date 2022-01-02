// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
// https://www.geeksforgeeks.org/ugly-numbers/
// https://www.youtube.com/watch?v=okH3HAPWTVs


/*
Brute Force - 
    Loop for all positive integers till the ugly number count is smaller than n
    if an integer is ugly than increment ugly number count
    To check if a number is ugly, divide the number by greatest divisible powers of 2, 3 and 5
    if the number becomes 1 then it is an ugly number otherwise not. 

    This method is not time efficient as it checks for all integers until ugly number count
    becomes n, but space complexity of this method is O(1) 
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int divides(int a,int b)
    {
        while(a%b==0)
        {
            a=a/b;
        }
        return a;
    }
    int isugly(int n)
    {
        n=divides(n,2);
        n=divides(n,3);
        n=divides(n,5);
        return (n==1)?1:0;
    }
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    int i = 1;
	    int count = 1;
	    while(n!=count)
	    {
	        i++;
	        if(isugly(i))
	        {
	            count++;
	        }
	    }
	    return i;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends


/*

Dynamic Programming - 

    1 Declare an array for ugly numbers:  ugly[n]
    2 Initialize first ugly no:  ugly[0] = 1
    3 Initialize three array index variables i2, i3, i5 to point to 
    1st element of the ugly array: 
            i2 = i3 = i5 =0; 
    4 Initialize 3 choices for the next ugly no:
            next_mulitple_of_2 = ugly[i2]*2;
            next_mulitple_of_3 = ugly[i3]*3
            next_mulitple_of_5 = ugly[i5]*5;
    5 Now go in a loop to fill all ugly numbers till 150:
    For (i = 1; i < 150; i++ ) 
    {
        /* These small steps are not optimized for good 
        readability. Will optimize them in C program 
        next_ugly_no  = Min(next_mulitple_of_2,
                            next_mulitple_of_3,
                            next_mulitple_of_5); 

        ugly[i] =  next_ugly_no       

        if (next_ugly_no  == next_mulitple_of_2) 
        {             
            i2 = i2 + 1;        
            next_mulitple_of_2 = ugly[i2]*2;
        } 
        if (next_ugly_no  == next_mulitple_of_3) 
        {             
            i3 = i3 + 1;        
            next_mulitple_of_3 = ugly[i3]*3;
        }            
        if (next_ugly_no  == next_mulitple_of_5)
        {    
            i5 = i5 + 1;        
            next_mulitple_of_5 = ugly[i5]*5;
        } 
        
    }/* end of for loop 
    6.return next_ugly_no
    

    https://www.youtube.com/watch?v=okH3HAPWTVs

    Time Complexity: O(n) 
    Auxiliary Space: O(n)

*/

// C++ program to find n'th Ugly number
#include <bits/stdc++.h>
using namespace std;

// Function to get the nth ugly number
unsigned getNthUglyNo(unsigned n)
{
	// To store ugly numbers
	unsigned ugly[n];
	unsigned i2 = 0, i3 = 0, i5 = 0;
	unsigned next_multiple_of_2 = 2;
	unsigned next_multiple_of_3 = 3;
	unsigned next_multiple_of_5 = 5;
	unsigned next_ugly_no = 1;

	ugly[0] = 1;
	for (int i = 1; i < n; i++) {
		next_ugly_no = min(
			next_multiple_of_2,
			min(next_multiple_of_3, next_multiple_of_5));
		ugly[i] = next_ugly_no;
		if (next_ugly_no == next_multiple_of_2) {
			i2 = i2 + 1;
			next_multiple_of_2 = ugly[i2] * 2;
		}
		if (next_ugly_no == next_multiple_of_3) {
			i3 = i3 + 1;
			next_multiple_of_3 = ugly[i3] * 3;
		}
		if (next_ugly_no == next_multiple_of_5) {
			i5 = i5 + 1;
			next_multiple_of_5 = ugly[i5] * 5;
		}
	}

	// End of for loop (i=1; i<n; i++)
	return next_ugly_no;
}

// Driver Code
int main()
{
	int n = 150;
	cout << getNthUglyNo(n);
	return 0;
}


/*

    Using SET Data Structure
    SET data structure to store the minimum of the 3 generated ugly numbers which will the
    ith Ugly Number stored at the first position of the set. 
    SET Data Structure as a set stores all the element in ascending order

    Time Complexity:- O(N log N)
    Auxiliary Space:- O(N)

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	   set < long long int > s;
	   s.insert(1);
	   n--;
	   while(n--)
	   {
	       auto it=s.begin();
	       long long int x = *it;
	       s.erase(it);
	       s.insert(x*2);
	       s.insert(x*3);
	       s.insert(x*5);
	   }
	   return *s.begin();
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends