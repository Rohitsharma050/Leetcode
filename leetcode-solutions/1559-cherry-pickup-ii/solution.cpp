class Solution {
public:
vector<vector<vector<int>>>dp;
int solve(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid)
{
    if(j1<0 || j2<0 || j1>=m || j2>=m)
    return 0;
    if(i==n-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }
    int ans = -1e8;
    for(int di = -1;di<=1;di++)
    {
        for(int dj = -1;dj<=1;dj++)
        {
            if(j1==j2)
            {
                ans = max(ans,grid[i][j1]+solve(i+1,j1+di,j2+dj,n,m,grid));
            }
            else
            {
                ans = max(ans,grid[i][j1]+grid[i][j2]+solve(i+1,j1+di,j2+dj,n,m,grid));
            }
        }
    }
    return dp[i][j1][j2] = ans;

}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(0,0,m-1,n,m,grid);
    }
};
