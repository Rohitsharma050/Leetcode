class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.size();
        
        // If the lengths of s and t are different, return false immediately
        if (n != t.size()) return false;

        // Frequency arrays for characters in both strings
        int f1[26] = {0};
        int f2[26] = {0};
        
        // To count the number of differences between s and t
        int swapCount = 0;
        vector<int> diffIndex; // To track the indices where s and t differ

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                swapCount++;
                diffIndex.push_back(i); // Store the index where they differ
            }
            // Update frequency counts
            f1[s[i] - 'a']++;
            f2[t[i] - 'a']++;
        }

        // Case 1: When the strings are identical (swapCount == 0), we need at least one duplicate character
        if (swapCount == 0) {
            for (int i = 0; i < 26; i++) {
                if (f1[i] > 1) return true; // Found a duplicate character
            }
            return false; // No duplicates, so cannot swap
        }

        // Case 2: When the strings differ in exactly two positions
        if (swapCount == 2) {
            // The two differing characters should be swappable
            if (s[diffIndex[0]] == t[diffIndex[1]] && s[diffIndex[1]] == t[diffIndex[0]]) {
                return true;
            }
        }

        return false; // If none of the above conditions are met, return false
    }
};

