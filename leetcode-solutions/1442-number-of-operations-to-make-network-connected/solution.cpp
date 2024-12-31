class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<int> adj[]) {
        visited[node] = 1; // Mark the current node as visited
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int v = connections.size(); // Number of edges
        
        // If the number of edges is less than (n - 1), it's impossible to connect all nodes
        if ((n - 1) > v) return -1;
        
        // Create an adjacency list for the graph
        vector<int> adj[n];
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, 0); // Visited array to track visited nodes
        int connectedComponents = 0; // Count of connected components
        
        // Perform DFS for each unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
                connectedComponents++;
            }
        }
        
        // Number of operations required is the number of extra connections to merge components
        return connectedComponents - 1;
    }
};

