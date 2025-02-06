class Solution {
public:
    typedef pair<int, int> P;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);

        // Construct adjacency list (1-based to 0-based indexing)
        for (auto time : times) {
            int u = time[0] - 1;  // Convert 1-based to 0-based
            int v = time[1] - 1;
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // Distance vector initialized to INF
        vector<int> dist(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from k-1 (0-based)
        pq.push({0, k - 1});
        dist[k - 1] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;

            for (auto neigh : adj[node]) {
                int adjNode = neigh.first;
                int currTime = neigh.second;
                
                // Relaxation step
                if (currTime + time < dist[adjNode]) {
                    dist[adjNode] = currTime + time;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Get max time to reach any node
        int ans = *max_element(dist.begin(), dist.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};

