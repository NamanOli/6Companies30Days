// https://practice.geeksforgeeks.org/problems/word-search/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool wordFound(vector<vector<char>>& board, string word, int index, int i, int j, int height, int width, int wordlen)
    {
        if((index+1)==wordlen)
            return true;
        if(i>height || j> width)
        {
            return false;
        }
        if((i>0)&& board[i-1][j]==word[index+1])
        {
            board[i][j]='1';
            
            bool val=wordFound(board, word, index+1, i-1,j,height,width,wordlen);
            if(val)
                return true;
            board[i][j]=word[index];
        }
        if((i<(height-1))&& board[i+1][j]==word[index+1])
        {
            board[i][j]='1';
            
            bool val=wordFound(board, word, index+1, i+1,j,height,width,wordlen);
            if(val)
                return true;
            board[i][j]=word[index];
        }
        if((j>0)&& board[i][j-1]==word[index+1])
        {
            board[i][j]='1';
            
            bool val=wordFound(board, word, index+1, i,j-1,height,width,wordlen);
            if(val)
                return true;
            board[i][j]=word[index];
        }
        if((j<(width-1))&& board[i][j+1]==word[index+1])
        {
            board[i][j]='1';
            bool val=wordFound(board, word, index+1, i,j+1,height,width,wordlen);
            if(val)
                return true;
            board[i][j]=word[index];
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        stack<pair<int,int>> stk;
        int height=board.size(),width=board[0].size(),wordlen=word.size();
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(board[i][j]==word[0])
                {
                    bool res=wordFound(board, word, 0, i,j,height,width,wordlen);
                    if(res)
                        return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends