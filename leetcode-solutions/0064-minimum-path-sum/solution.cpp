class Solution {
public:
    long long solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // If out of bounds, return large value (not INT_MAX to avoid overflow)
        if(i >= n || j >= m)
            return 1e9;

        // If already at destination, return the value at that cell
        if(i == n - 1 && j == m - 1)
            return grid[i][j];

        // If already computed, return stored result
        if(dp[i][j] != -1)
            return dp[i][j];

        // Move right and down recursively
        long long right = solve(i + 1, j, n, m, grid, dp);
        long long down = solve(i, j + 1, n, m, grid, dp);

        // Store and return the result
        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Initialize memoization table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(0, 0, n, m, grid, dp);
    }
};

