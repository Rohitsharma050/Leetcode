class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list representation (node -> {neighbor, cost})
        vector<pair<int, int>> adj[n];
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v, cost});
        }

        // Queue for BFS (stops, {cost, node})
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}}); // {stops, {cost, node}}

        // Distance array to store the minimum cost to reach each node
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int cost = it.second.first;
            int node = it.second.second;

            // If we exceed the allowed stops, stop further traversal
            if (stops > k) continue;

            // Explore neighbors
            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int currCost = neighbor.second;

                // If a cheaper way to reach adjNode is found, update distance and push into queue
                if (cost + currCost < dist[adjNode]) {
                    dist[adjNode] = cost + currCost;
                    q.push({stops + 1, {dist[adjNode], adjNode}});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};

