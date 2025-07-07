class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by their start day
        sort(events.begin(), events.end());

        // Min-heap to store event end days
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 0, i = 0, n = events.size(), attended = 0;

        // Find the last possible day from the events
        int lastDay = 0;
        for (const auto& e : events) {
            lastDay = max(lastDay, e[1]);
        }

        // For each day from 1 to last possible day
        for (day = 1; day <= lastDay; ++day) {
            // Add all events that start today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }

            // Remove all events that already ended
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend the event that ends the earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                ++attended;
            }
        }

        return attended;
    }
};


