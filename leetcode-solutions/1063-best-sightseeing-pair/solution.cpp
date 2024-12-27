class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i = values[0]; // Initialize the maximum value of values[i] + i
        int ans = 0;           // Initialize the result

        for (int j = 1; j < values.size(); j++) {
            // Update the answer with the current pair (max_i + values[j] - j)
            ans = max(ans, max_i + values[j] - j);
            // Update max_i to include the current element
            max_i = max(max_i, values[j] + j);
        }

        return ans;
    }
};

