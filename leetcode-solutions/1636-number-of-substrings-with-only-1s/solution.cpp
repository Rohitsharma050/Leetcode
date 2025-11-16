class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long ones = 0;
        long long mod = 1e9 + 7;

        long long inv2 = 500000004; // modular inverse of 2 under 1e9+7

        for(char c : s) {
            if(c == '1') {
                ones++;
            } else {
                ans = (ans + (ones % mod * ((ones + 1) % mod) % mod) * inv2 % mod) % mod;
                ones = 0;
            }
        }

        // last block of ones
        ans = (ans + (ones % mod * ((ones + 1) % mod) % mod) * inv2 % mod) % mod;

        return ans;
    }
};

