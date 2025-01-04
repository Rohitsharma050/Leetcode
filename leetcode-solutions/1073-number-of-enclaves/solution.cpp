class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // first row
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                q.push({0, i});
                visited[0][i] = 1;
            }
        }

        // first col 
        for (int i = 1; i < n; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
        }

        // last row
        for (int i = 1; i < m; i++) {
            if (grid[n - 1][i] == 1) {
                q.push({n - 1, i});
                visited[n - 1][i] = 1;
            }
        }

        // last col
        for (int i = 1; i < n - 1; i++) {
            if (grid[i][m - 1] == 1) {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int nrow[4] = {1, -1, 0, 0};
            int ncol[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int row = r + nrow[i];
                int col = c + ncol[i];
                if (isvalid(row, col, n, m) && grid[row][col] == 1 && visited[row][col] == 0) {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

