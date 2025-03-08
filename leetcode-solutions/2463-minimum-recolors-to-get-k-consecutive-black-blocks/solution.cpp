
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minRecolors = k; // Worst case: all 'W' in the window

        // Count 'W' in the first window of size k
        int whiteCount = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }
        minRecolors = whiteCount;

        // Slide the window across the string
        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') whiteCount--; // Remove leftmost character
            if (blocks[i] == 'W') whiteCount++; // Add new rightmost character
            minRecolors = min(minRecolors, whiteCount);
        }

        return minRecolors;
    }
};


