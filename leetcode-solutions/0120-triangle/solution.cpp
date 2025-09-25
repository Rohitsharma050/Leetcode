class Solution {
public:
int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp)
{
    if(i==n)
    return 0;
    if(dp[i][j]!=1e6)
    return dp[i][j];
    return dp[i][j] = triangle[i][j]+ min(solve(i+1,j,n,triangle,dp),solve(i+1,j+1,n,triangle,dp));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e6));
        return solve(0,0,n,triangle,dp);
    }
};
