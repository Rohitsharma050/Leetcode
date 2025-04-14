class Solution {
public:
    const int m = 1e9 + 7;
    
    long long modPow(long long a, long long b) {
        if (b == 0)
            return 1;
        long long half = modPow(a, b / 2);
        long long res = (half * half) % m;
        if (b & 1) {
            res = (res * a) % m;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2; // digits at even indices: 0, 2, 4... can be 0-9 -> 5 choices
        long long odd_positions = n / 2;        // digits at odd indices: 1, 3, 5... can be 0-9 excluding vowels -> 4 choices
        long long ans = (modPow(5, even_positions) * modPow(4, odd_positions)) % m;
        return (int)ans;
    }
};

