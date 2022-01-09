// https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#

1. // { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(vector<vector<int>> mat, int row, int col)
    {
        // cout<<mat[row][col]<<" ";
        for(int i=0; i<9; ++i)
            if(i != col && mat[row][i] == mat[row][col])
            {
                // cout<<row<<" "<<i<<endl;
                return true;
            }
                
        for(int i=0; i<9; ++i)
            if(i != row && mat[i][col] == mat[row][col])
            {
                // cout<<i<<" "<<col<<endl;
                return true;
            }
        
        for(int i=0; i<9; ++i)
        {
            int r1 = 3*(row/3) + i/3, c1 = 3*(col/3) + i%3;
            if((r1 != row || c1 != col) && mat[r1][c1] == mat[row][col])
            {
                // cout<<r1<<" "<<c1<<endl;
                return true;
            }
        }
        
        return false;
    }
    
    int isValid(vector<vector<int>> mat){
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(mat[i][j] == 0)
                    continue;
                if(check(mat, i, j))
                    return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends



2. 
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
            int R = mat.size();
    int C = mat[0].size();
    
    unordered_map<int ,int> rows[9];
    unordered_map<int,int> columns[9];
    unordered_map<int,int> boxes[9];
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int ch = mat[i][j]; 
            
            if(ch != 0 && (rows[i][ch]++ > 0 || columns[j][ch]++ > 0 || boxes[i/3*3+j/3][ch]++ > 0))
                return false;
        }
    }
    return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends