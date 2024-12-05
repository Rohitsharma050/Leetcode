class Solution {
public:
    bool canChange(string start, string target) {
        // Step 1: Remove all underscores to ensure characters match in order.
        string s_clean, t_clean;
        for (char c : start) if (c != '_') s_clean += c;
        for (char c : target) if (c != '_') t_clean += c;

        if (s_clean != t_clean) return false; // If characters don't match, return false.

        int n = start.size();
        int i = 0, j = 0;

        // Step 2: Check positions of 'L'
        while (i < n && j < n) {
            // Move i and j to the next 'L' in start and target, respectively
            while (i < n && start[i] != 'L') i++;
            while (j < n && target[j] != 'L') j++;

            // If one string ends before the other
            if (i < n && j < n) {
                // 'L' cannot move to the right
                if (i < j) return false;
                i++;
                j++;
            }
        }

        i = 0;
        j = 0;

        // Step 3: Check positions of 'R'
        while (i < n && j < n) {
            // Move i and j to the next 'R' in start and target, respectively
            while (i < n && start[i] != 'R') i++;
            while (j < n && target[j] != 'R') j++;

            // If one string ends before the other
            if (i < n && j < n) {
                // 'R' cannot move to the left
                if (i > j) return false;
                i++;
                j++;
            }
        }

        return true;
    }
};

