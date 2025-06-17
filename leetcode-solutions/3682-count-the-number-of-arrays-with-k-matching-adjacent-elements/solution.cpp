class Solution {
    static const int MOD = 1e9 + 7;

    // Fast exponentiation modulo MOD
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        // Precompute factorials and inverse factorials up to n
        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);

        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2); // Fermat inverse

        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        // nCk helper
        auto nCk = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        long long ways = nCk(n - 1, k);         // Choose k adjacent matches
        ways = ways * m % MOD;                  // First group choice
        ways = ways * modPow(m - 1, n - k - 1) % MOD;  // Remaining group choices
        return (int)ways;
    }
};

