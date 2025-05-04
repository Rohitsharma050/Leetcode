class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N; // 2^N
        vector<vector<int>> grid(size, vector<int>(size, 0));
        fillGrid(grid, 0, 0, size, 0); // start from (0,0), size = 2^N, start value = 0
        return grid;
    }

private:
    void fillGrid(vector<vector<int>>& grid, int row, int col, int size, int start) {
        if (size == 1) {
            grid[row][col] = start;
            return;
        }

        int half = size / 2;
        int quadSize = half * half;

        // Fill TR (top-right)
        fillGrid(grid, row, col + half, half, start);
        // Fill BR (bottom-right)
        fillGrid(grid, row + half, col + half, half, start + quadSize);
        // Fill BL (bottom-left)
        fillGrid(grid, row + half, col, half, start + 2 * quadSize);
        // Fill TL (top-left)
        fillGrid(grid, row, col, half, start + 3 * quadSize);
    }
};

