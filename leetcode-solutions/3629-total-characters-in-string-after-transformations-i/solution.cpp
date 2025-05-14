class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);
        
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int step = 0; step < t; ++step) {
            vector<long long> next(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (i < 25) {
                    next[i + 1] = (next[i + 1] + freq[i]) % MOD;
                } else { // i == 25, i.e. 'z'
                    next[0] = (next[0] + freq[i]) % MOD;  // 'a'
                    next[1] = (next[1] + freq[i]) % MOD;  // 'b'
                }
            }
            freq = next;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % MOD;
        }

        return (int)result;
    }
};
