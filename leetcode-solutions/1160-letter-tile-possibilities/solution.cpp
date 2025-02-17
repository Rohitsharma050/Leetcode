class Solution {
public:
    // Recursive backtracking function
    int backtrack(vector<int>& freq) {
        int count = 0;
        // Iterate over all 26 uppercase letters
        for (int i = 0; i < 26; i++) {
            // If the character is available (frequency > 0)
            if (freq[i] > 0) {
                // Choose the character
                freq[i]--;
                // Count the current sequence and continue recursion
                count += 1 + backtrack(freq);
                // Backtrack by restoring the character's frequency
                freq[i]++;
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        // Frequency array to count each character's occurrence
        vector<int> freq(26, 0);
        for (char ch : tiles) {
            freq[ch - 'A']++;
        }
        // Start backtracking to count all possible sequences
        return backtrack(freq);
    }
};

