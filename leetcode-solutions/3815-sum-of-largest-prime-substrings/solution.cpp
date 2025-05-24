#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(long long num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        long long limit = sqrt(num);
        for (long long i = 3; i <= limit; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> primeSet;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            string numStr = "";
            for (int j = i; j < n; ++j) {
                numStr += s[j];
                try {
                    long long num = stoll(numStr); // use stoll instead of stoi
                    if (isPrime(num)) {
                        primeSet.insert(num);
                    }
                } catch (...) {
                    // Skip if conversion fails (e.g., number too large)
                    continue;
                }
            }
        }

        vector<long long> primes(primeSet.begin(), primeSet.end());
        sort(primes.rbegin(), primes.rend());

        long long sum = 0;
        for (int i = 0; i < min(3, (int)primes.size()); ++i) {
            sum += primes[i];
        }
        return sum;
    }
};

