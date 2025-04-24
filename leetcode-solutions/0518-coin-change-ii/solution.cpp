class Solution {
public:
int solve(int i,int target,int n,vector<int>& coins,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;
    if(target==0)
    return 1;
    if(target<0)
    return 0;
    if(dp[i][target]!=-1)
    {
        return dp[i][target];
    }
    int take = solve(i,target-coins[i],n,coins,dp);
    int nottake = solve(i+1,target,n,coins,dp);
    return dp[i][target] = take+nottake;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,n,coins,dp);
    }
};
