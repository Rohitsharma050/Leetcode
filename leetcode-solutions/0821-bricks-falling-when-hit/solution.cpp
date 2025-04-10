#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union with Union by Size
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSize(int x, int y) {
        int x_root = findParent(x);
        int y_root = findParent(y);
        if (x_root == y_root) return;
        if (size[x_root] > size[y_root]) {
            parent[y_root] = x_root;
            size[x_root] += size[y_root];
        } else {
            parent[x_root] = y_root;
            size[y_root] += size[x_root];
        }
    }

    int getSize(int x) {
        return size[findParent(x)];
    }
};

class Solution {
public:
    // Check if cell is within grid bounds
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // Convert 2D (i,j) to 1D index
    int index(int i, int j, int n) {
        return i * n + j;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        int roof = total;  // Virtual node for roof
        DisjointSet ds(total + 1); // DSU for total cells + 1 virtual node

        vector<vector<int>> copyGrid = grid;

        // Step 1: Apply all hits in advance
        for (auto& hit : hits) {
            int x = hit[0], y = hit[1];
            if (copyGrid[x][y] == 1)
                copyGrid[x][y] = 0;
        }

        // Directions: up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 2: Build DSU from remaining grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (copyGrid[i][j] == 1) {
                    int curr = index(i, j, n);
                    if (i == 0) {
                        ds.unionSize(curr, roof); // Connect top row to roof
                    }
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (isValid(ni, nj, m, n) && copyGrid[ni][nj] == 1) {
                            int neighbor = index(ni, nj, n);
                            ds.unionSize(curr, neighbor);
                        }
                    }
                }
            }
        }

        vector<int> res(hits.size());

        // Step 3: Process hits in reverse
        for (int i = hits.size() - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1];

            // If original grid had no brick, skip
            if (grid[x][y] == 0) {
                res[i] = 0;
                continue;
            }

            // Get size of roof component before restoring
            int prevRoofSize = ds.getSize(roof);

            // Restore the brick in copyGrid
            copyGrid[x][y] = 1;
            int currIdx = index(x, y, n);

            // If it's in the top row, connect it to roof
            if (x == 0) {
                ds.unionSize(currIdx, roof);
            }

            // Connect to all adjacent bricks
            for (int k = 0; k < 4; ++k) {
                int ni = x + dr[k];
                int nj = y + dc[k];
                if (isValid(ni, nj, m, n) && copyGrid[ni][nj] == 1) {
                    int neighbor = index(ni, nj, n);
                    ds.unionSize(currIdx, neighbor);
                }
            }

            // Get size of roof component after restoring
            int currRoofSize = ds.getSize(roof);

            // Bricks that fell = new connections - the one brick we added
            res[i] = max(0, currRoofSize - prevRoofSize - 1);
        }

        return res;
    }
};

