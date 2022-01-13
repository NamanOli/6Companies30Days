// https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    pair<char,char> comp(string a,string b)
    {
        int n = min(a.size(),b.size());
        for(int i=0;i<n;++i)
        {
            if(a[i]!=b[i])
            {
                return make_pair(a[i],b[i]);
            }
           
        }
        return make_pair('%','%');
    }
    void topologicalSort(stack<int>&s,vector<bool>&b,vector<vector<int>>&a,int i)
    {
        b[i]=true;
        for(int j=0;j<a[i].size();++j)
        {
            if(b[a[i][j]]==false)
            {
                topologicalSort(s,b,a,a[i][j]);
            }
        }
        s.push(i);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>a(K);
        for(int i=0;i<N-1;++i)
        {
            pair<char,char>b = comp(dict[i],dict[i+1]);
            if(b.first=='%')
            {
                continue;
            }
          //cout<<b.first<<" "<<b.second<<endl;
            int c=b.first-'a';
            int d=b.second-'a';
        //  cout<<c<<" "<<d<<endl;
          a[c].push_back(d);
        }
        vector<bool>b(K,false);
        stack<int>s;
        for(int i=0;i<K;++i)
        {
            if(b[i]==false&& a[i].size()>0)
            {
                topologicalSort(s,b,a,i);
            }
        }
        string ans="";
        while(!s.empty())
        {
            int a = s.top();
         // cout<<a<<"stack"<<endl;
            s.pop();
            char c = 'a'+a;
            ans+=c;
        }
        for(int i=0;i<K;++i)
        {
            if(b[i]==false)
            {
                char c = 'a'+i;
                 ans+=c;
            }
        }
    //  cout<<ans;
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends