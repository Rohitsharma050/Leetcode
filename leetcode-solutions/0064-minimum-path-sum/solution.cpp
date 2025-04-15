class Solution {
public:
vector<vector<int>>dp;
int getsum(int i,int j,int n,int m,vector<vector<int>>& grid)
{
    if(i>=n || j>=m)
    return INT_MAX;
    if(i==n-1 && j==m-1)
    return grid[i][j];
    if(dp[i][j]!=-1)
    return dp[i][j];
    int right = getsum(i+1,j,n,m,grid);
    int bottom = getsum(i,j+1,n,m,grid);
    return dp[i][j] = grid[i][j]+min(right,bottom);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return getsum(0,0,n,m,grid);

    }
};
