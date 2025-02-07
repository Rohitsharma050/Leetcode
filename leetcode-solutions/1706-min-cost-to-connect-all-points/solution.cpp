class Solution {
public:
    typedef pair<int, int> P;
    
    int prims(int n, vector<vector<pair<int, int>>>& adj) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});
        int cost = 0;
        
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            
            if (visited[node])
                continue;
            
            visited[node] = true;
            cost += wt;
            
            for (auto neigh : adj[node]) {
                int adjpoint = neigh.first;
                int adjwt = neigh.second;
                if (!visited[adjpoint]) {
                    pq.push({adjwt, adjpoint});
                }
            }
        }
        return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int d = abs(x2 - x1) + abs(y2 - y1);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        
        int totalcost = prims(n, adj);
        return totalcost;
    }
};

