class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        unordered_map<int, int> dp;
        int maxLen = 0;

        // Store index of each number in arr
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Iterate through pairs (A[j], A[i])
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int prev = arr[i] - arr[j];
                
                // Check if prev exists and its index is before j
                if (index.count(prev) && index[prev] < j) {
                    int k = index[prev] * n + j;
                    dp[j * n + i] = dp[k] + 1;
                    maxLen = max(maxLen, dp[j * n + i] + 2);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};
