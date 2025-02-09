class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
     int n = grid.size();
    
    // Sort the bottom-left triangle (including the middle diagonal) in non-increasing order
    for (int d = 0; d < n; ++d) {
        vector<int> diagonal;
        int i = d, j = 0;
        while (i < n && j < n) {
            diagonal.push_back(grid[i][j]);
            i++;
            j++;
        }
        sort(diagonal.rbegin(), diagonal.rend()); // Sort in non-increasing order
        i = d, j = 0;
        int idx = 0;
        while (i < n && j < n) {
            grid[i][j] = diagonal[idx++];
            i++;
            j++;
        }
    }
    
    // Sort the top-right triangle in non-decreasing order
    for (int d = 1; d < n; ++d) {
        vector<int> diagonal;
        int i = 0, j = d;
        while (i < n && j < n) {
            diagonal.push_back(grid[i][j]);
            i++;
            j++;
        }
        sort(diagonal.begin(), diagonal.end()); // Sort in non-decreasing order
        i = 0, j = d;
        int idx = 0;
        while (i < n && j < n) {
            grid[i][j] = diagonal[idx++];
            i++;
            j++;
        }
    }
    
    return grid;
    }
};
