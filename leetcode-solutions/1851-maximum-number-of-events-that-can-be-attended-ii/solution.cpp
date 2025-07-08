class Solution {
public:
    vector<vector<int>> dp;

    // Binary search to find the next event that starts after events[index][1]
    int binarySearch(vector<vector<int>>& events, int index) {
        int left = index + 1, right = events.size() - 1;
        int next = events.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > events[index][1]) {
                next = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return next;
    }

    // Recursively solve with memoization
    int solve(int i, int k, vector<vector<int>>& events) {
        if (i == events.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        // Option 1: Skip the current event
        int skip = solve(i + 1, k, events);

        // Option 2: Attend the current event
        int nextIndex = binarySearch(events, i);
        int take = events[i][2];
        if (nextIndex < events.size()) {
            take += solve(nextIndex, k - 1, events);
        }

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // Sort by start day
        dp = vector<vector<int>>(events.size(), vector<int>(k + 1, -1));
        return solve(0, k, events);
    }
};

