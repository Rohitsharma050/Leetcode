class Solution {
public:
int solve(int i,int j,int n,int m, vector<vector<int>>&matrix,  vector<vector<int>>&dp){
    if(i>=n || j>=m || matrix[i][j]==0 ){
        return 0;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    int right = solve(i,j+1,n,m,matrix,dp);
    int down  = solve(i+1,j,n,m,matrix,dp);
    int di = solve(i+1,j+1,n,m,matrix,dp);
    return dp[i][j] = 1+min({right,down,di});
}
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                ans+=solve(i,j,n,m,matrix,dp);
            }
        }
        return ans;
    }
};
