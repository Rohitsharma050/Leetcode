class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeros = 0;
        int n = s.size();
        for (char ch : s) {
            if (ch == '0') zeros++;
        }

        int count = zeros;
        long long val = 0;
        int power = 0;

        // Go from right to left, trying to add 1s only if valid
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (power < 31) {
                    long long temp = val + (1LL << power);
                    if (temp <= k) {
                        val = temp;
                        count++;
                        power++;
                    }
                }
            } else {
                power++;
            }
        }

        return count;
    }
};

