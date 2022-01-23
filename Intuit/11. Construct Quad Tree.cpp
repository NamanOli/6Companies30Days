// https://leetcode.com/problems/construct-quad-tree/

class Solution {
public:
    Node* rec_construct(vector<vector<int>>& grid,int row_start,int row_end,int col_start,int col_end,int factor)
    {
        int sum=0;
        for(int i=row_start;i<row_end;i++)
        {
            for(int j=col_start;j<col_end;j++)
            {
                sum+=grid[i][j];
            }
        }
        Node* ans;
        if(sum==0)
            ans=new Node(false,true);
        else if(sum==(factor*factor))
            ans=new Node(true,true);
        else
        {
            ans=new Node(false,false);
            factor=factor/2;
            ans->topLeft = rec_construct(grid,row_start,row_start+factor,col_start,col_start+factor,factor);
            ans->topRight = rec_construct(grid,row_start,row_start+factor,col_start+factor,col_end,factor);
            ans->bottomLeft = rec_construct(grid,row_start+factor,row_end,col_start,col_start+factor,factor);
            ans->bottomRight = rec_construct(grid,row_start+factor,row_end,col_start+factor,col_end,factor);
        }
        return ans;
        
    }
    Node* construct(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        Node* ans = rec_construct(grid,0,n,0,n,n);
        return ans;
    }
};