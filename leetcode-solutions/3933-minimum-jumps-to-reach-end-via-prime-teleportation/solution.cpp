class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (int d = 3; d * (long long)d <= x; d += 2)
            if (x % d == 0) return false;
        return true;
    }

    void factor(int x, vector<int>& primes) {
        if (x % 2 == 0) {
            primes.push_back(2);
            while (x % 2 == 0) x /= 2;
        }
        for (int d = 3; d * (long long)d <= x; d += 2) {
            if (x % d == 0) {
                primes.push_back(d);
                while (x % d == 0) x /= d;
            }
        }
        if (x > 1) primes.push_back(x);
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> byPrime;
        byPrime.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            vector<int> facs;
            factor(nums[i], facs);
            for (int p : facs) {
                byPrime[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front(); q.pop();
            int d = dist[i];
            if (i + 1 < n && dist[i+1] == -1) {
                dist[i+1] = d + 1;
                if (i+1 == n-1) return dist[i+1];
                q.push(i+1);
            }
            if (i - 1 >= 0 && dist[i-1] == -1) {
                dist[i-1] = d + 1;
                q.push(i-1);
            }
            if (isPrime(nums[i])) {
                auto &vec = byPrime[nums[i]];
                for (int j : vec) {
                    if (j != i && dist[j] == -1) {
                        dist[j] = d + 1;
                        if (j == n-1) return dist[j];
                        q.push(j);
                    }
                }
                vec.clear();
            }
        }

        return -1;
    }
};

