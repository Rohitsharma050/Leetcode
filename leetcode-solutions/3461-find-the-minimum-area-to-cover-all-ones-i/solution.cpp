class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxrow = INT_MIN, maxcol = INT_MIN, minrow = INT_MAX , mincol = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    maxrow = max(maxrow,i);
                    maxcol = max(maxcol,j);
                    mincol = min(mincol,j);
                    minrow = min(minrow,i);
                }
            }
        }
        return (maxrow-minrow+1)*(maxcol-mincol+1);
    }
};
