class Solution {
public:
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    int n,m;
    bool valid(int i,int j)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
         int fresh = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                fresh++;
            }
        }
        if(fresh==0)
        return 0;
        if(q.empty())
        return -1;
        
        int ans = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = max(ans,t);
            for(int i = 0;i<4;i++)
            {
                int nextrow = r+row[i];
                int nextcol = c+col[i];
                if(valid(nextrow,nextcol) && grid[nextrow][nextcol]==1)
                {
                    q.push({{nextrow,nextcol},t+1});
                    grid[nextrow][nextcol] = 2;
                    fresh--;
                }
            }

        }
        //for(int i =0;i<n;i++)
        // {
        //     for(int j = 0;j<m;j++)
        //     {
        //         if(grid[i][j]==1)
        //         return -1;
        //     }
        // }
        return fresh==0?ans:-1;
    }
};
