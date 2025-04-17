#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int bfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        // Directions to explore: up, down, left, right
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Initialize queue for BFS and size of the island
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;  // Mark the cell as visited
        int islandSize = 1;

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Explore the four directions
            for (int d = 0; d < 4; d++) {
                int newi = x + dr[d];
                int newj = y + dc[d];

                // If the new cell is valid and contains land (1), add it to the queue
                if (isvalid(newi, newj, n, m) && grid[newi][newj] == 1) {
                    grid[newi][newj] = 0;  // Mark the cell as visited
                    q.push({newi, newj});
                    islandSize++;
                }
            }
        }

        return islandSize;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        // Traverse all the cells in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If it's land (1), perform BFS to find the size of the island
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, bfs(grid, i, j, n, m));
                }
            }
        }

        return maxArea;
    }
};

