#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    // dp[i][mode][rem] = max profit starting at day i,
    // mode = 0 (free), 1 (holding normal buy), 2 (holding short sell),
    // rem = transactions remaining.
    vector<vector<vector<long long>>> dp;

    long long dfs(int i, int mode, int rem, const vector<int>& prices) {
        // Base cases
        if (i == n) {
            // reached end of days
            return mode == 0 ? 0LL : LLONG_MIN/2;
        }
        if (rem == 0) {
            // no transactions left
            return mode == 0 ? 0LL : LLONG_MIN/2;
        }
        long long &ans = dp[i][mode][rem];
        if (ans != LLONG_MIN) return ans;

        // If free, we can:
        //  1) start a normal buy  → move to mode 1, no rem change, pay prices[i]
        //  2) start a short sell  → move to mode 2, no rem change, gain prices[i]
        //  3) skip day            → stay in mode 0
        if (mode == 0) {
            long long buyNormal  = dfs(i+1, 1, rem, prices) - prices[i];
            long long sellShort  = dfs(i+1, 2, rem, prices) + prices[i];
            long long skip       = dfs(i+1, 0, rem, prices);
            ans = max({buyNormal, sellShort, skip});
        }
        // If holding a normal buy, we can:
        //  1) sell → move to free mode, rem−1, gain prices[i]
        //  2) hold → stay in mode 1
        else if (mode == 1) {
            long long doSell = dfs(i+1, 0, rem-1, prices) + prices[i];
            long long hold   = dfs(i+1, 1, rem, prices);
            ans = max(doSell, hold);
        }
        // If holding a short sell, we can:
        //  1) buy back → move to free mode, rem−1, pay prices[i]
        //  2) hold    → stay in mode 2
        else { // mode == 2
            long long buyBack = dfs(i+1, 0, rem-1, prices) - prices[i];
            long long hold    = dfs(i+1, 2, rem, prices);
            ans = max(buyBack, hold);
        }

        return ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        // initialize dp with LLONG_MIN sentinel
        dp.assign(n+1,
                  vector<vector<long long>>(3,
                                            vector<long long>(k+1, LLONG_MIN)));
        return dfs(0, 0, k, prices);
    }
};

