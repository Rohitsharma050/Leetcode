class Solution {
public:
int solve(int i,int canbuy,int n,vector<int>& prices,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][canbuy]!=-1)
    return dp[i][canbuy];
    if(canbuy)
    {
        int buy = solve(i+1,0,n,prices,dp)-prices[i];
        int notbuy = solve(i+1,1,n,prices,dp);
        return dp[i][canbuy] =  max(buy,notbuy);
    }
    else
    {
        int sell = prices[i]+solve(i+2,1,n,prices,dp);
        int notsell = solve(i+1,0,n,prices,dp);
        return dp[i][canbuy] =  max(sell,notsell);
    }
    
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,n,prices,dp);
    }
};
