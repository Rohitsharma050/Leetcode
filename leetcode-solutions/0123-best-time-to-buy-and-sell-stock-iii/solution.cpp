// class Solution {
// public:
// int solve(int i,bool canbuy,int trans,int n,vector<int>& prices,vector<vector<vector<int>>>&dp)
// {
//     if(i==n)
//     {
//         return 0;
//     }
//     if(dp[i][canbuy][trans]!=-1)
//     return dp[i][canbuy][trans];
//     if(canbuy)
//     {
//         if(trans>0)
//         {
//             int buy = solve(i+1,0,trans,n,prices,dp)-prices[i];
//             int notbuy = solve(i+1,1,trans,n,prices,dp);
//             return dp[i][canbuy][trans]= max(buy,notbuy);
//         }
//     }
//     else
//     {
//             int sell = prices[i]+solve(i+1,1,trans-1,n,prices,dp);
//             int notsell = solve(i+1,0,trans,n,prices,dp);
//             return  dp[i][canbuy][trans]=  max(sell,notsell);
//     }
//     return 0;
// }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(0,1,2,n,prices,dp);
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i = n-1;i>=0;i--)
        {
            for(int canbuy = 0;canbuy<=1;canbuy++)
            {
                for(int trans = 1;trans<=2;trans++)
                {

                    if(canbuy)
                    {
                        if(trans>0)
                        {
                            int buy = dp[i+1][0][trans]-prices[i];
                            int notbuy = dp[i+1][1][trans];
                             dp[i][canbuy][trans]= max(buy,notbuy);
                        }
                    }
                    else
                    {
                            int sell = prices[i]+dp[i+1][1][trans-1];
                            int notsell = dp[i+1][0][trans];
                            dp[i][canbuy][trans]=  max(sell,notsell);
                    }


                }
            }
        }
        return dp[0][1][2];
    }
};
