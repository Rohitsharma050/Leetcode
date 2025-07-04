class Solution {
public:
    char shift(char c, int times) {
        return (c - 'a' + times) % 26 + 'a';
    }

    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths;
        long long len = 1;
        for (int op : operations) {
            if (op == 0) {
                len *= 2;
            } else {
                len *= 2;
            }
            lengths.push_back(len);
            if (len >= k) break;  // no need to go further
        }

        char res = 'a';
        for (int i = lengths.size() - 1; i >= 0; --i) {
            len = lengths[i] / 2;

            if (k > len) {
                k -= len;
                if (operations[i] == 1) {
                    res = shift(res, 1);  // shift one time since we're moving into the shifted section
                }
                // if op == 0, nothing changes
            }
            // else, k stays the same and res stays the same
        }
        return res;
    }
};

