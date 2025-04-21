class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long prefix_sum = 0, min_val = 0, max_val = 0;
        for (int diff : differences) {
            prefix_sum += diff;
            min_val = min(min_val, prefix_sum);
            max_val = max(max_val, prefix_sum);
        }
        return max(0L, (upper - lower) - (max_val - min_val) + 1);
    }
};

