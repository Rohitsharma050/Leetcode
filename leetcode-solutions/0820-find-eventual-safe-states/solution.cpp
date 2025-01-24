class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph

        // Step 1: Reverse the graph to analyze incoming edges
        vector<vector<int>> adj(n); // Adjacency list for the reversed graph
        vector<int> indeg(n, 0);    // Array to store in-degrees of nodes

        // Build the reversed graph and calculate in-degrees
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
                indeg[i]++;
            }
        }

        // Step 2: Identify nodes with zero in-degree
        queue<int> q; // Queue for nodes to process
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                // Nodes with zero in-degree are initially safe
                q.push(i);
            }
        }

        // Step 3: Perform topological sorting (Kahn's Algorithm)
        vector<int> ans; // Stores the eventual safe nodes
        while (!q.empty()) {
            int node = q.front(); // Get the current node
            q.pop();
            ans.push_back(node); // Add it to the safe nodes list

            // Process all nodes that point to the current node in the reversed graph
            for (int i = 0; i < adj[node].size(); i++) {
                indeg[adj[node][i]]--; // Decrease the in-degree of the neighbor
                if (indeg[adj[node][i]] == 0) {
                    // If the in-degree becomes zero, it's now safe
                    q.push(adj[node][i]);
                }
            }
        }

        // Step 4: Sort the safe nodes in ascending order
        // This ensures the result is returned in lexicographical order
        sort(ans.begin(), ans.end());

        return ans; // Return the list of eventual safe nodes
    }
};

