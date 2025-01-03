class Solution {
public:
    // Helper function to check if a cell is within the board boundaries
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();  // Number of rows in the board
        int m = board[0].size();  // Number of columns in the board
        queue<pair<int, int>> q;  // Queue for BFS traversal

        // Process the first row (top border)
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '1';  // Mark as visited and not surrounded
            }
        }

        // Process the first column (left border)
        for (int i = 1; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '1';  // Mark as visited and not surrounded
            }
        }

        // Process the last row (bottom border)
        for (int j = 0; j < m; j++) {
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = '1';  // Mark as visited and not surrounded
            }
        }

        // Process the last column (right border)
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = '1';  // Mark as visited and not surrounded
            }
        }

        // BFS to mark all 'O's connected to the border
        while (!q.empty()) {
            int r = q.front().first;  // Current row
            int c = q.front().second; // Current column
            q.pop();

            // Possible moves: up, down, left, right
            int nrow[4] = {1, -1, 0, 0};
            int ncol[4] = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                int row = r + nrow[k];
                int col = c + ncol[k];
                // Check if the cell is valid and contains 'O'
                if (isValid(row, col, n, m) && board[row][col] == 'O') {
                    q.push({row, col});
                    board[row][col] = '1';  // Mark as visited
                }
            }
        }

        // Update the board: convert all '1' (not surrounded) back to 'O'
        // and all remaining 'O' (surrounded) to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';  // Border-connected 'O's
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Surrounded 'O's
                }
            }
        }
    }
};

