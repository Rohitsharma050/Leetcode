class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Build the adjacency list for the tree
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int count = 0;  // To store the number of valid components

        // Define the DFS function
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long subtree_sum = values[node]; // Use long long for large sums
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {  // Avoid revisiting the parent
                    subtree_sum += dfs(neighbor, node);
                }
            }

            // Check if the subtree sum is divisible by k
            if (subtree_sum % k == 0) {
                ++count;  // Increment the count of valid components
                return 0LL; // Reset the sum as this subtree forms a valid component
            }
            return subtree_sum; // Return the sum to the parent node
        };

        dfs(0, -1); // Start DFS from the root node (0) with no parent
        return count; // Return the total count of valid components
    }
};
