class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,int n ,int m,vector<vector<int>>& grid)
{
     if(i>=n || j>=m)
    return 0;
     if(grid[i][j]==1)
    return 0;

    if(i==n-1 && j==m-1)
    return 1;
   
   
     if(dp[i][j]!=-1)
   return dp[i][j];
    int right = solve(i+1,j,n,m,grid);
    int left = solve(i,j+1,n,m,grid);
    return dp[i][j] = right+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,grid);
    }
};
