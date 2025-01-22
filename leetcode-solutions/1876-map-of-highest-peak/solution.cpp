class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
     int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1)); // Initialize all cells as unvisited
    queue<pair<int, int>> q; // BFS queue

    // Add all water cells to the queue and set their height to 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isWater[i][j] == 1) {
                height[i][j] = 0; // Water cells start at height 0
                q.push({i, j});
            }
        }
    }

    // Directions for moving to 4-connected neighbors
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // BFS to assign heights
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            // If the neighbor is within bounds and unvisited
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                height[nx][ny] = height[x][y] + 1; // Increment height
                q.push({nx, ny}); // Add neighbor to the queue
            }
        }
    }

    return height;
    }
};
