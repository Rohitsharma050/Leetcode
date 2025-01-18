class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
    int n = arr.size();
    
    // Cost without rearranging (absolute difference)
    long long noRearrangeCost = 0;
    for (int i = 0; i < n; ++i) {
        noRearrangeCost += abs(arr[i] - brr[i]);
    }
    
    // Cost with rearranging
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    
    long long rearrangeCost = k;
    for (int i = 0; i < n; ++i) {
        rearrangeCost += abs(arr[i] - brr[i]);
    }
    
    // Return the minimum of the two costs
    return min(noRearrangeCost, rearrangeCost);
    }
};
