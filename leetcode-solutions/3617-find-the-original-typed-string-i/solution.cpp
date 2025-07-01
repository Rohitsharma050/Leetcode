class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int freq = 1;
        bool used = false;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (word[i] == word[i + 1]) {
                freq++;
            } else {
                if (!used && freq > 1) {
                    ans += freq;
                    used = true;
                } else if (freq > 1) {
                    ans += freq - 1;
                }
                freq = 1;
            }
        }

        // Process the last group
        if (!used && freq > 1) {
            ans += freq;
        } else if (freq > 1) {
            ans += freq - 1;
        }

        return ans==0?1:ans;
    }
};

