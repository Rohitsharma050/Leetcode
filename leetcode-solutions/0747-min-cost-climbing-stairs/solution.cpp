class Solution {
public:
int n;
int solve(int i,vector<int>&dp,vector<int>&cost)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    return dp[i];
    int take = cost[i]+solve(i+1,dp,cost);
    int nottake = cost[i]+solve(i+2,dp,cost);
    return dp[i]  = min(take,nottake);
}
    int minCostClimbingStairs(vector<int>& cost) {
         n=cost.size();
        vector<int>dp1(n+1,-1);
         vector<int>dp2(n+1,-1);
        return min(solve(0,dp1,cost),solve(1,dp2,cost));
    }
};
