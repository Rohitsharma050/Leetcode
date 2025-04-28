class Solution {
public:
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
bool isvalid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
int dfs(int i,int j,int n,int m,int &maxarea, vector<vector<int>>&vis,vector<vector<int>>& grid)
{
    vis[i][j] = 1;
    maxarea++;
    for(int k = 0;k<4;k++)
    {
        int newi = i+dr[k];
        int newj = j+dc[k];
        if(isvalid(newi,newj,n,m) && vis[newi][newj]==0 && grid[newi][newj]==1)
        {
            dfs(newi,newj,n,m,maxarea,vis,grid);
        }
    }
    return maxarea;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxarea = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                int area = 0;
                if(grid[i][j]==1 && !vis[i][j])
                {
                    maxarea = max(maxarea,dfs(i,j,n,m,area,vis,grid));
                }
                vis[i][j]=1;
            }
        }
        
        return maxarea;
    }
};
