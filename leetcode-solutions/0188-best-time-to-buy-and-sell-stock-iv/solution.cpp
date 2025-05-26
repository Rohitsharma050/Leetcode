class Solution {
public:  
int maxProfit1(vector<int>& prices,int k) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i = n-1;i>=0;i--)
        {
            for(int canbuy = 0;canbuy<=1;canbuy++)
            {
                for(int trans = 1;trans<=k;trans++)
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
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return maxProfit1(prices,k);
        
    }
};
