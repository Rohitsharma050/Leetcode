class Solution {
public:
    // Declare a 2D DP table for memoization
    vector<vector<int>> dp;

    // Recursive function to find the minimum number of coins
    int solve(int i, int n, int amount, vector<int>& coins) {
        // Base Case: If amount is exactly 0, no more coins are needed
        if (amount == 0) {
            return 0;
        }

        // Base Case: If amount is negative or we've gone through all coins
        if (amount < 0 || i >= n) {
            return 1e9; // Use a large number to represent an invalid path
        }

        // If the result for this state is already computed, return it
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // Choice 1: Take the current coin and stay at the same index (unbounded)
        int take = 1 + solve(i, n, amount - coins[i], coins);

        // Choice 2: Skip the current coin and move to the next
        int nottake = solve(i + 1, n, amount, coins);

        // Store and return the minimum of both choices
        return dp[i][amount] = min(take, nottake);
    }

    // Main function to initiate the recursion
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Initialize dp table with -1 (indicating uncomputed states)
        dp = vector<vector<int>>(n + 1, vector<int>(amount + 1, -1));

        // Start recursion from index 0
        int res = solve(0, n, amount, coins);

        // If no valid way was found, return -1
        return res == 1e9 ? -1 : res;
    }
};

