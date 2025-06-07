class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
          int n = x.size();
    unordered_map<int, int> maxY; // Map from x[i] to the max y[i]

    // Step 1: For each unique x[i], store the max y[i]
    for (int i = 0; i < n; ++i) {
        if (maxY.find(x[i]) == maxY.end()) {
            maxY[x[i]] = y[i];
        } else {
            maxY[x[i]] = max(maxY[x[i]], y[i]);
        }
    }

    // Step 2: If we have less than 3 unique x[i], return -1
    if (maxY.size() < 3) return -1;

    // Step 3: Put all max y[i] values in a vector
    vector<int> maxYValues;
    for (auto& [key, val] : maxY) {
        maxYValues.push_back(val);
    }

    // Step 4: Sort and take the top 3 values
    sort(maxYValues.rbegin(), maxYValues.rend()); // Descending sort

    return maxYValues[0] + maxYValues[1] + maxYValues[2];
    }
};
