class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (j < 0 || j >= m) return 1e9;
        if (i == n - 1) return matrix[i][j];

        if (dp[i][j] != INT_MAX) return dp[i][j];

        // Recurse into the three possible directions
        int down = matrix[i][j] + solve(i + 1, j, n, m, matrix, dp);
        int downLeft = matrix[i][j] + solve(i + 1, j - 1, n, m, matrix, dp);
        int downRight = matrix[i][j] + solve(i + 1, j + 1, n, m, matrix, dp);

        // Store the result in dp and return
        return dp[i][j] = min({down, downLeft, downRight});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int result = INT_MAX;

        for (int j = 0; j < m; j++) {
            result = min(result, solve(0, j, n, m, matrix, dp));
        }

        return result;
    }
};

