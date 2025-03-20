#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank, min_cost;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        min_cost.resize(n, (1 << 17) - 1);  // Initialize with all bits set
        iota(parent.begin(), parent.end(), 0); // Each node is its own parent initially
    }
    
    int find(int u) {
        if (parent[u] != u) 
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }
    
    void unite(int u, int v, int w) {
        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u != root_v) {
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
                min_cost[root_v] &= min_cost[root_u] & w;
            } else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
                min_cost[root_u] &= min_cost[root_v] & w;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
                min_cost[root_u] &= min_cost[root_v] & w;
            }
        } else {
            min_cost[root_u] &= w;  // Update cost for same component
        }
    }
    
    int getMinCost(int u, int v) {
        if (find(u) == find(v)) return min_cost[find(u)];
        return -1;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n);
        
        for (auto& edge : edges) {
            dsu.unite(edge[0], edge[1], edge[2]);
        }
        
        vector<int> result;
        for (auto& query : queries) {
            if (query[0] == query[1]) 
                result.push_back(0);
            else 
                result.push_back(dsu.getMinCost(query[0], query[1]));
        }
        
        return result;
    }
};

