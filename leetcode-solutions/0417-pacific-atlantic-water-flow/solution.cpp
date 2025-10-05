class Solution {
public:
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int r,int c,int m,int n,vector<vector<int>>&ocean,vector<vector<int>>&heights)
{
    
    ocean[r][c] = 1;
    for(int i = 0;i<4;i++)
    {
        int newr = r+dir[i][0];
        int newc = c+dir[i][1];
        if(newr>=m || newc>=n || newr<0 || newc<0)
        continue ;
        if(heights[newr][newc]<heights[r][c])
        continue;
        if(ocean[newr][newc]!=1)
        {
            dfs(newr,newc,m,n,ocean,heights);
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>pacific(m, vector<int>(n, 0));
        vector<vector<int>>atlantic(m, vector<int>(n, 0));
        //upper edge
        for(int i = 0;i<n;i++)
        {
            dfs(0,i,m,n,pacific,heights);
        }
        //left edge
        for(int i = 0;i<m;i++)
        {
            dfs(i,0,m,n,pacific,heights);
        }
        //bottom edge
        for(int i = 0;i<n;i++)
        {
            dfs(m-1,i,m,n,atlantic,heights);
        }
        //right edge
        for(int i = 0;i<m;i++)
        {
            dfs(i,n-1,m,n,atlantic,heights);
        }

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
