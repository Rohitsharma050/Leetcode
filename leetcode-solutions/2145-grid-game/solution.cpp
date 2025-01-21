class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
          int n = grid[0].size();
    vector<long long> topSum(n, 0), bottomSum(n, 0);

    // Calculate prefix sums for the bottom row
    bottomSum[0] = grid[1][0];
    for (int i = 1; i < n; i++) {
        bottomSum[i] = bottomSum[i - 1] + grid[1][i];
    }

    // Calculate suffix sums for the top row
    topSum[n - 1] = grid[0][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        topSum[i] = topSum[i + 1] + grid[0][i];
    }

    // Minimize the maximum points Player 2 can get
    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long player2Points = max((i > 0 ? bottomSum[i - 1] : 0), (i < n - 1 ? topSum[i + 1] : 0));
        result = min(result, player2Points);
    }

    return result;
    }
};
