class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Min-heap to store pairs of (distance, point)
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> minHeap;

    // Step 1: Compute the distances and push into the heap
    for (auto& point : points) {
        int x = point[0], y = point[1];
        int distance = x * x + y * y; // Squared distance to avoid floating-point precision issues
        minHeap.push({distance, point});
    }

    // Step 2: Extract the k closest points
    vector<vector<int>> result;
    while (k-- > 0 && !minHeap.empty()) {
        result.push_back(minHeap.top().second); // Get the point
        minHeap.pop(); // Remove the top element
    }
    return result;
    }
};
