class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
          int m = mat.size();
    int n = mat[0].size();
    
    // Mapping each value to its (row, col) position
    unordered_map<int, pair<int, int>> position;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            position[mat[i][j]] = {i, j};
        }
    }
    
    // Count painted cells for rows and columns
    vector<int> rowCount(m, 0), colCount(n, 0);
    
    for (int i = 0; i < arr.size(); ++i) {
        auto [r, c] = position[arr[i]];
        rowCount[r]++;
        colCount[c]++;
        
        if (rowCount[r] == n || colCount[c] == m) {
            return i;
        }
    }
    
    return -1; // Should never reach here if input guarantees a solution
    }
};
