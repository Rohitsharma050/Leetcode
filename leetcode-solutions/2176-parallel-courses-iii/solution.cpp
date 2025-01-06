class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        vector<int> maxtime(n, 0);

        // Build adjacency list and indegree array
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            adj[u].push_back(v);
            indeg[v]++;
        }

        // Initialize queue and maxtime
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                maxtime[i] = time[i]; // Time to complete a course with no prerequisites
            }
        }

        // Topological sort and calculate maximum time
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neigh : adj[node]) {
                maxtime[neigh] = max(maxtime[neigh], maxtime[node] + time[neigh]);
                indeg[neigh]--;
                if (indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // Return the maximum time among all courses
        return *max_element(maxtime.begin(), maxtime.end());
    }
};

