class Solution {
public:
int getways(int n,vector<int>&dp)
{
    if(n<=1)
    return 1;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n] = getways(n-1,dp)+getways(n-2,dp);
}

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return getways(n,dp);
    }
};
