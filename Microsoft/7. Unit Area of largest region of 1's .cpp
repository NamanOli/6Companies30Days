// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        
        int n= (int)grid.size();
        int m=(int)grid[0].size();
        
        int vis[n][m];
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        vis[i][j]=0;
        
        int area=0,count;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    vis[i][j]=1;
                    q.push(make_pair(i,j));
                    
                    count=1;
                    
                    while(!q.empty())
                    {
                        pair<int,int> temp= q.front();
                        q.pop();
                        int x=temp.first;
                        int y=temp.second;
                        if(x+1<n && grid[x+1][y] && vis[x+1][y]==0)
                        {
                            vis[x+1][y]=1;
                            count++;
                            q.push(make_pair(x+1,y));
                        }
                        
                        if(y+1<m && grid[x][y+1] && vis[x][y+1]==0)
                        {
                            vis[x][y+1]=1;
                            count++;
                            q.push(make_pair(x,y+1));
                        }
                        
                        if(x-1>=0 && grid[x-1][y] && vis[x-1][y]==0)
                        {
                            vis[x-1][y]=1;
                            count++;
                            q.push(make_pair(x-1,y));
                        }
                        
                        if(y-1>=0 && grid[x][y-1] && vis[x][y-1]==0)
                        {
                            vis[x][y-1]=1;
                            count++;
                            q.push(make_pair(x,y-1));
                        }
                        
                        if(x+1<n  && y+1<m && grid[x+1][y+1] && vis[x+1][y+1]==0)
                        {
                            vis[x+1][y+1]=1;
                            count++;
                            q.push(make_pair(x+1,y+1));
                        }
                        if(x-1>=0 && y-1>=0 && grid[x-1][y-1] && vis[x-1][y-1]==0)
                        {
                            vis[x-1][y-1]=1;
                            count++;
                            q.push(make_pair(x-1,y-1));
                        }
                        
                        if(x+1<n && y-1>=0 && grid[x+1][y-1] && vis[x+1][y-1]==0)
                        {
                            vis[x+1][y-1]=1;
                            count++;
                            q.push(make_pair(x+1,y-1));
                        }
                        
                        if(x-1>=0 && y+1<m && grid[x-1][y+1] && vis[x-1][y+1]==0)
                        {
                            vis[x-1][y+1]=1;
                            count++;
                            q.push(make_pair(x-1,y+1));
                        }
                    }
                    
                    area=max(area,count);
                }
            }
        }
        return area;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends