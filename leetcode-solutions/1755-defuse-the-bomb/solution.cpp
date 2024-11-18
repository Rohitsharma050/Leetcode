class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
          int n = code.size();
    vector<int> result(n, 0);
    
    if (k == 0) {
        // If k == 0, all elements in the result are 0
        return result;
    }
    
    int start = k > 0 ? 1 : k;  // Start of the sliding window
    int end = k > 0 ? k : -1;   // End of the sliding window
    int window_sum = 0;

    // Calculate the initial window sum
    for (int i = start; i <= end; ++i) {
        window_sum += code[(i + n) % n];
    }

    // Slide the window for each element
    for (int i = 0; i < n; ++i) {
        result[i] = window_sum;

        // Update the sliding window
        window_sum -= code[(i + start + n) % n];
        window_sum += code[(i + end + 1 + n) % n];
    }
    
    return result;

    }
};
