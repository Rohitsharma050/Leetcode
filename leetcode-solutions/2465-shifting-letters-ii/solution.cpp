class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> totalShift(n + 1, 0); // Use an extra space for easier range updates

        // Apply the shifts
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            // Increment or decrement the range
            if (dir == 1) {
                totalShift[start]++;
                totalShift[end + 1]--;
            } else {
                totalShift[start]--;
                totalShift[end + 1]++;
            }
        }

        // Calculate the prefix sum for the shifts
        for (int i = 1; i < n; i++) {
            totalShift[i] += totalShift[i - 1];
        }

        // Apply the shifts to the string
        for (int i = 0; i < n; i++) {
            int shift = totalShift[i] % 26; // Reduce the shift to within alphabet range
            if (shift < 0) {
                shift += 26; // Handle negative shifts
            }
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};

