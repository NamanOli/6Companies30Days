// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    bool isValid(int m , int n , int x, int y){ // Check if valid
        if(x<0||x>=m || y<0||y>=n)return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x ,int y){ // dfs
        int m = heights.size();
        int n = heights[0].size();
        
        visited[x][y] = true; // mark visited
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i = 0 ; i < 4; i++){ // iterated all valid neighbours
            if(isValid(m, n , x + dx[i] ,  y + dy[i]) && 
               !visited[x + dx[i]][y+dy[i]] && 
               heights[x][y]<=heights[x + dx[i]][y + dy[i]])
            {
                dfs(heights, visited, x + dx[i], y + dy[i]);
            }
        }
        
    } 
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans; // For returning answers
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> visPac(m , vector<bool>(n, false));
        vector<vector<bool>> visAtl(m , vector<bool>(n, false));
        
        for(int i = 0 ; i < m ; i++){
            dfs(heights, visPac, i , 0);
            dfs(heights, visAtl, i , n-1);
        }
        
        for(int i = 0 ; i < n ; i++){
            dfs(heights, visPac, 0 , i);
            dfs(heights, visAtl, m-1 , i);
        }
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(visPac[i][j] && visAtl[i][j]){ // if can reach both oceans
                    ans.push_back({i, j});
                }
            }
        }
        
       return ans; 
    }
};