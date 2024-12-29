class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
         int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        int count = 0;

        // Iterate through each column
        for (int j = 0; j < n; j++) {
            // Check every pair of consecutive rows in the column
            for (int i = 1; i < m; i++) {
                if (grid[i][j] <= grid[i - 1][j]) {
                    // Increment grid[i][j] to be greater than grid[i-1][j]
                    int diff = grid[i - 1][j] - grid[i][j] + 1;
                    count += diff;
                    grid[i][j] += diff;
                }
            }
        }

        return count;
    }
};

