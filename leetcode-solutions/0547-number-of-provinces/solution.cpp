class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<int> adj[]) {
        visited[node] = 1;
        for (int n : adj[node]) {
            if (!visited[n]) {
                dfs(n, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adjMat) {
        int v = adjMat.size();
        vector<int> adj[v];
        
        // Construct adjacency list
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adjMat[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<int> visited(v, 0);

        // Perform DFS to count connected components
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
                count++;
            }
        }
        return count;
    }
};

