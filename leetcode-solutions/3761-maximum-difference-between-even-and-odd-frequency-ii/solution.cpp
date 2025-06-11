class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;

        // Function to compute a 2-bit state from parity of cntA and cntB
        auto getState = [](int cntA, int cntB) {
            return ((cntA & 1) << 1) | (cntB & 1);  // 2-bit state
        };

        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;

                vector<int> best(4, INT_MAX / 2);  // best[state] = min(prefixA - prefixB)
                int cntA = 0, cntB = 0;
                int prevA = 0, prevB = 0, left = -1;

                for (int r = 0; r < n; ++r) {
                    cntA += (s[r] == a);
                    cntB += (s[r] == b);

                    while (r - left >= k && cntB - prevB >= 2) {
                        int st = getState(prevA, prevB);
                        best[st] = min(best[st], prevA - prevB);
                        ++left;
                        prevA += (s[left] == a);
                        prevB += (s[left] == b);
                    }

                    int st = getState(cntA, cntB);
                    int target = st ^ 2;  // flip parity of a (odd requirement)
                    if (best[target] < INT_MAX / 2) {
                        ans = max(ans, cntA - cntB - best[target]);
                    }
                }
            }
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};

