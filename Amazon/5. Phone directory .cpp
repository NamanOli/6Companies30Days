// https://practice.geeksforgeeks.org/problems/phone-directory4628/1/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int len = s.length();
        vector<vector<string>> ans; 
        ans.clear();
    
        for(int i=1; i<=len; i++){
            
            string str = s.substr(0,i);
            vector<string> v;
            unordered_set<string> s;
            v.clear();
            for(int j=0; j<n; j++){
                
                if(str == contact[j].substr(0,i)){
                    if(s.find(contact[j]) == s.end())
                    v.push_back(contact[j]); 
                }
                s.insert(contact[j]);
                
            }
            sort(v.begin(), v.end());
            if(v.size() == 0) {
                ans.push_back({"0"});
            }
            else ans.push_back(v);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends