class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        // Iterate only over valid starting indices for substrings of length k
        for (int j = 0; j <= n - k; j++) {
            string sub = s.substr(j, k);
            bool isUniform = true;
            // Check if all characters in sub are the same.
            for (int i = 1; i < k; i++) {
                if (sub[i] != sub[0]) {
                    isUniform = false;
                    break;
                }
            }
            if (!isUniform)
                continue;
            
            // Check the left neighbor if it exists.
            if (j > 0 && s[j - 1] == sub[0])
                continue;
            
            // Check the right neighbor if it exists.
            if (j + k < n && s[j + k] == sub[0])
                continue;
            
            // Found a valid substring.
            return true;
        }
        return false;
    }
};
