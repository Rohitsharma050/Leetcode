#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int N = matrix.size();
        int M = matrix[0].size();

        vector<int> result;
        result.reserve(N * M);

        vector<int> intermediate;

        for (int d = 0; d < N + M - 1; d++) {
            intermediate.clear();

            int r = (d < M) ? 0 : d - M + 1;
            int c = (d < M) ? d : M - 1;

            while (r < N && c >= 0) {
                intermediate.push_back(matrix[r][c]);
                r++;
                c--;
            }

            if (d % 2 == 0) {
                reverse(intermediate.begin(), intermediate.end());
            }

            result.insert(result.end(), intermediate.begin(), intermediate.end());
        }

        return result;
    }
};

