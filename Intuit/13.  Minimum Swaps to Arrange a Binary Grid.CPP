//https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0; i<n; i++) {
            int cnt=0;
            for(int j=grid[i].size()-1; j>=0&&grid[i][j]==0; j--,cnt++);
            grid[i].push_back(cnt);
        }
        int pos=n-1,ans=0;
        for(int i=0; i<n; i++) {
             bool found=false;
             if(grid[i].back()<pos) {
                 for(int r=i+1; r<n; r++) {
                       if(grid[r].back()>=pos) {
                            found=true;
                            for(int k=r; k>i; k--) {
                                 swap(grid[k],grid[k-1]);
                                 ans++;
                            }
                           break;
                       }
                 }
             }else {
                 found=true;
             }
            if(!found) return -1;
            pos--;
        }
        return ans;
    }
};
