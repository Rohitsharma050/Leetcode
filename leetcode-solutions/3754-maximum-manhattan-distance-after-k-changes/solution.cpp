class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        // Try all 4 direction combinations: NE, NW, SE, SW
        const string dirs[4] = {"NE", "NW", "SE", "SW"};
        for (auto &dir : dirs) {
            ans = max(ans, calc(s, k, dir));
        }
        return ans;
    }

private:
    int calc(const string &s, int k, const string &dir) {
        int res = 0;
        int curr = 0, flips = 0;
        for (char c : s) {
            if (dir.find(c) != string::npos) {
                // If c is in direction set, move positively
                curr++;
            } else {
                // Otherwise, use a flip if available
                if (flips < k) {
                    flips++;
                    curr++;
                } else {
                    curr--;
                }
            }
            res = max(res, curr);
        }
        return res;
    }
};

