class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
           if (heightMap.empty() || heightMap[0].empty()) return 0;

        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Min-Heap to store {height, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        // Push all boundary cells into the heap
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    minHeap.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        int waterTrapped = 0;
        vector<int> directions = {0, 1, 0, -1, 0}; // to explore 4 neighbors

        // Process cells in the heap
        while (!minHeap.empty()) {
            auto cell = minHeap.top();
            minHeap.pop();
            int height = cell[0], row = cell[1], col = cell[2];

            // Explore 4 neighbors
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];

                // Check bounds and whether the cell is visited
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    // Water trapped depends on the difference in height
                    waterTrapped += max(0, height - heightMap[newRow][newCol]);
                    // Push the updated height into the heap
                    minHeap.push({max(height, heightMap[newRow][newCol]), newRow, newCol});
                }
            }
        }

        return waterTrapped;
    }
};
