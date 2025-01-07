class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Corrected the size of the matrix
        vector<vector<bool>> check(n, vector<bool>(n, false));
        
        // Fill the adjacency matrix based on prerequisites
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            check[u][v] = true;
        }

        // Using Floyd-Warshall algorithm to find transitive closure
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    check[i][j] = check[i][j] || (check[i][k] && check[k][j]);
                }
            }
        }

        // Answer the queries
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {   
            int u = queries[i][0];
            int v = queries[i][1];
            ans.push_back(check[u][v]);
        }

        return ans;
    }
};

