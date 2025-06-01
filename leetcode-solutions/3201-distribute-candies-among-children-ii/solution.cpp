class Solution {
public:
    long long distributeCandies(int n, int limit) {
         if (n > 3 * limit) return 0;

        auto comb = [](int n, int k) -> long long {
            if (n < 0 || k < 0 || k > n) return 0;
            long long res = 1;
            for (int i = 1; i <= k; ++i) {
                res = res * (n - i + 1) / i;
            }
            return res;
        };

        long long total = comb(n + 2, 2);
        long long subtract1 = 3 * comb(n - limit + 1, 2);
        long long add2 = 3 * comb(n - 2 * limit, 2);
        long long subtract3 = comb(n - 3 * limit - 1, 2);

        return total - subtract1 + add2 - subtract3;
    }
};
