class Solution {
public:
    // Check if a string is a palindrome
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    // Convert a number to base k
    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += char('0' + num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Main function to find the sum of first n k-mirror numbers
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // Try palindromes of increasing lengths
        for (int length = 1; count < n; ++length) {
            int half = (length + 1) / 2;
            long long start = pow(10, half - 1), end = pow(10, half);

            for (long long i = start; i < end && count < n; ++i) {
                string left = to_string(i);
                string right = left;
                if (length % 2 == 1)
                    right.pop_back();
                reverse(right.begin(), right.end());
                string full = left + right;
                long long num = stoll(full);
                string baseK = toBaseK(num, k);
                if (isPalindrome(baseK)) {
                    sum += num;
                    count++;
                }
            }
        }

        return sum;
    }
};

