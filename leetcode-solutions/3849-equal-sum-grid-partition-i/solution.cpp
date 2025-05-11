class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    vector<long long> rowPrefix(m, 0), colPrefix(n, 0);
    long long total = 0;

    // Compute rowPrefix and total sum
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rowPrefix[i] += grid[i][j];
            colPrefix[j] += grid[i][j];
            total += grid[i][j];
        }
    }

    // Prefix sum for rows
    for (int i = 1; i < m; ++i) {
        rowPrefix[i] += rowPrefix[i - 1];
    }

    // Check horizontal cuts
    for (int i = 0; i < m - 1; ++i) {
        if (rowPrefix[i] * 2 == total)
            return true;
    }

    // Prefix sum for columns
    for (int j = 1; j < n; ++j) {
        colPrefix[j] += colPrefix[j - 1];
    }

    // Check vertical cuts
    for (int j = 0; j < n - 1; ++j) {
        if (colPrefix[j] * 2 == total)
            return true;
    }

    return false;
    }
};
