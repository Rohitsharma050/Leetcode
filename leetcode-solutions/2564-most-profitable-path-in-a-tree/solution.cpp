#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to determine the time at which Bob reaches each node
    bool bobtraversal(vector<vector<int>>& adj, unordered_map<int, int>& bobTime, vector<bool>& vis, int node, int time) {
        vis[node] = 1; // Mark the node as visited
        bobTime[node] = time; // Store the time Bob reaches this node
        if (node == 0) return true; // If Bob reaches node 0, stop the traversal
        
        for (auto neigh : adj[node]) { // Explore all neighbors
            if (!vis[neigh]) { // If neighbor is not visited
                if (bobtraversal(adj, bobTime, vis, neigh, time + 1)) { // Recursively traverse
                    return true;
                }
            }
        }
        
        bobTime.erase(node); // Remove the node if it does not lead to 0
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) { 
        int n = amount.size();
        vector<vector<int>> adj(n); // Adjacency list representation of the tree
        
        // Construct the adjacency list
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int, int> bobTime; // Stores time Bob reaches each node
        vector<bool> vis(n, 0); // Visited array for Bob's traversal
        bobtraversal(adj, bobTime, vis, bob, 0); // Find Bob's path and timings
        
        int aliceIncome = INT_MIN; // Maximum profit Alice can obtain
        vector<bool> visited(n, 0); // Visited array for Alice's BFS traversal
        queue<vector<int>> q; // BFS queue
        q.push({0, 0, 0}); // {node, time, income}
        visited[0] = 1; // Mark root as visited
        
        while (!q.empty()) {
            int node = q.front()[0]; // Current node
            int time = q.front()[1]; // Alice's time at this node
            int income = q.front()[2]; // Alice's accumulated income
            q.pop();
            
            // Determine Alice's profit at this node based on Bob's arrival time
            if (bobTime.find(node) == bobTime.end() || bobTime[node] > time) {
                income += amount[node]; // Alice gets full amount if she arrives first
            } else if (bobTime[node] == time) {
                income += amount[node] / 2; // Alice gets half if they arrive simultaneously
            }
            
            // If node is a leaf (except the root), update max profit
            if (adj[node].size() == 1 && node != 0) {
                aliceIncome = max(aliceIncome, income);
            }
            
            // Traverse neighbors
            for (auto neigh : adj[node]) {
                if (!visited[neigh]) {
                    q.push({neigh, time + 1, income}); // Move to next node
                    visited[neigh] = 1; // Mark as visited
                }
            }
        }
        
        return aliceIncome; // Return the maximum income Alice can obtain
    }
};

