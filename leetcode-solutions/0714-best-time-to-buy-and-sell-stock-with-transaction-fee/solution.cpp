class Solution {
public:
 int maxProfit1(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //base case
        dp[n][0] = dp[n][1] = 0;
        for(int i = n-1;i>=0;i--)
        {
            for(int canbuy = 0;canbuy<=1;canbuy++)
            {
                if(canbuy)
                {
                    int buy = dp[i+1][0]-prices[i];
                    int notbuy = dp[i+1][1];
                    dp[i][canbuy] =  max(buy,notbuy);
                }
                else
                {
                    int sell = prices[i]+dp[i+1][1]-fee;
                    int notsell = dp[i+1][0];
                    dp[i][canbuy] =  max(sell,notsell);
                }

            }
        }
        return dp[0][1];
    }
  int maxProfit(vector<int>& prices, int fee) {
        return maxProfit1(prices,fee);
    }
};
