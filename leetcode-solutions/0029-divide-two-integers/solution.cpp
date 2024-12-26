class Solution {
public:
    int divide(int n, int m) {
        // Handle edge cases
        if (m == 0) return INT_MAX; // Division by zero
        if (n == INT_MIN && m == -1) return INT_MAX; // Overflow case
        
        // Determine the sign of the result
        bool isNegative = (n < 0) ^ (m < 0);

        // Work with absolute values
        long long dividend = abs((long long)n);
        long long divisor = abs((long long)m);

        long long ans = 0;

        // Perform the division using bit manipulation
        while (dividend >= divisor) {
            long long temp = divisor, multiple = 1;

            // Keep doubling the divisor until it exceeds the dividend
            while (dividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest multiple from the dividend
            dividend -= temp;
            ans += multiple;
        }

        // Apply the sign to the result
        return isNegative ? -ans : ans;
    }
};

