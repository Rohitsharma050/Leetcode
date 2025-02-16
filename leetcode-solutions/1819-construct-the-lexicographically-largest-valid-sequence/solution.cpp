class Solution {
public:
    // Main function to generate the lexicographically largest sequence
    vector<int> constructDistancedSequence(int n) {
        // Initialize result vector of size 2 * n - 1 with all elements as -1
        vector<int> ans(2 * n - 1, -1);
        // Boolean vector to track which numbers have been used
        vector<bool> used(n + 1, false);
        // Start the recursive backtracking function from index 0
        solve(0, n, ans, used);
        // Return the final constructed sequence
        return ans;
    }

    // Recursive backtracking function to construct the sequence
    bool solve(int i, int n, vector<int>& result, vector<bool>& used) {
        // Base case: If the current index is beyond the last position, a valid sequence is constructed
        if (i >= result.size())
            return true;

        // Skip already filled positions
        if (result[i] != -1) {
            return solve(i + 1, n, result, used);
        }

        // Try placing numbers from n to 1 to ensure lexicographical order
        for (int num = n; num >= 1; num--) {
            // Skip numbers that are already used
            if (used[num] == true) {
                continue;
            }

            // Mark the number as used and place it at the current index
            used[num] = true;
            result[i] = num;

            // Special case for 1 as it only occupies one position
            if (num == 1) {
                if (solve(i + 1, n, result, used))
                    return true;
            } else {  // General case for larger numbers
                // Calculate the second position as i + num
                int j = result[i] + i;
                // Check if the second position is within bounds and unoccupied
                if (j < result.size() && result[j] == -1) {
                    result[j] = num;
                    // Recursively solve for the next index
                    if (solve(i + 1, n, result, used)) {
                        return true;
                    }
                    // Backtrack by resetting the second position
                    result[j] = -1;
                }
            }

            // Undo the placement (Backtracking)
            used[num] = false;
            result[i] = -1;
        }

        // If no numbers can be placed at the current index, return false to backtrack
        return false;
    }
};

