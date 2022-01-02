// https://leetcode.com/problems/greatest-common-divisor-of-strings/


/*
Explanation - s1+s2 == s2+s1 if & only if s1 is a multiple of s2 or vice-versa
e.g. s1=abcabc, s2=abc, then s1+s2 = abcabcabc = s2+s1
This is a requirement for the strings to have a gcd. If one of them is NOT a multiple of other, gcd is ''

Since they are multiples, next step is simply to find the gcd of the lengths of 2 strings e.g. gcd(6,3) = 3, and get the substring of length 3 from either s1 or s2.
which is what s1.substr(0, gcd) does... and in Python, that would be s1[:gcd] or s2[:gcd]
*/

class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        return (s1 + s2 == s2 + s1)  
		    ? s1.substr(0, gcd(size(s1), size(s2)))
			: "";
    }
};