class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    vector<pair<int, int>> events;

    // Create events for start and end of each range
    for (int x : nums) {
        events.emplace_back(x - k, 1);    // Start of range
        events.emplace_back(x + k + 1, -1); // End of range (+1 to make it exclusive)
    }

    // Sort events by position; if same position, sort by type (start before end)
    sort(events.begin(), events.end());

    int maxBeauty = 0, activeRanges = 0;

    // Sweep line algorithm
    for (auto [pos, type] : events) {
        activeRanges += type; // Increment or decrement active ranges
        maxBeauty = max(maxBeauty, activeRanges); // Track maximum
    }

    return maxBeauty;
}
};
