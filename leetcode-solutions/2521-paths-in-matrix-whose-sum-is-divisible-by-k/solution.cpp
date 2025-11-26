class Solution {
public:
int n,m;
long long mod = 1e9+7;
int solve(int i ,int j,int rem,vector<vector<int>>& grid,int k,  vector<vector<vector<int>>>&dp)
{
    if(i==n-1 && j==m-1)
    {
        if((rem+grid[i][j])%k==0)
        return 1;
        return 0;
    }
    if(i>=n || j>=m)
    return 0;
    if(dp[i][j][rem]!=-1)
    return dp[i][j][rem];
    int right = solve(i,j+1,(rem+grid[i][j])%k,grid,k,dp);
    int down =  solve(i+1,j,(rem+grid[i][j])%k,grid,k,dp);
    return dp[i][j][rem] =  (right+down)%(mod);
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
         n = grid.size();
         m = grid[0].size();
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k,-1)));
        return solve(0,0,0,grid,k,dp);
    }
};
