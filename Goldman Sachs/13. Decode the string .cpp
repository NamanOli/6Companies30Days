// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
// https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/

/*
The idea is to use two stacks, one for integers and another for characters. 
Now, traverse the string, 

   - Whenever we encounter any number, push it into the integer stack and in case of any 
    alphabet (a to z) or open bracket (‘[‘), push it onto the character stack.

   - Whenever any close bracket (‘]’) is encounter pop the character from the character 
   stack until open bracket (‘[‘) is not found in the character stack. Also, pop the 
   top element from the integer stack, say n. Now make a string repeating the popped 
   character n number of time. Now, push all character of the string in the stack.
   
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string str){
        // code here
    stack<int> integerstack;
    stack<char> stringstack;
    string temp = "", result = "";

    // Traversing the string
    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;

        // If number, convert it into number
        // and push it into integerstack.
        if (str[i] >= '0' && str[i] <='9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            integerstack.push(count);
        }

        // If closing bracket ']', pop element until
        // '[' opening bracket is not found in the
        // character stack.
        else if (str[i] == ']')
        {
            temp = "";
            count = 0;

            if (! integerstack.empty())
            {
                count = integerstack.top();
                integerstack.pop();
            }

            while (! stringstack.empty() && stringstack.top()!='[' )
            {
                temp = stringstack.top() + temp;
                stringstack.pop();
            }

            if (! stringstack.empty() && stringstack.top() == '[')
                stringstack.pop();

            // Repeating the popped string 'temo' count
            // number of times.
            for (int j = 0; j < count; j++)
                result = result + temp;

            // Push it in the character stack.
            for (int j = 0; j < result.length(); j++)
                stringstack.push(result[j]);

            result = "";
        }

        // If '[' opening bracket, push it into character stack.
        else if (str[i] == '[')
        {
            if (str[i-1] >= '0' && str[i-1] <= '9')
                stringstack.push(str[i]);

            else
            {
                stringstack.push(str[i]);
                integerstack.push(1);
            }
        }

        else
            stringstack.push(str[i]);
    }

    // Pop all the element, make a string and return.
    while (! stringstack.empty())
    {
        result = stringstack.top() + result;
        stringstack.pop();
    }

    return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends